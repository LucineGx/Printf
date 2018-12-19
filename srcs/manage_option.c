/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_to_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:45:36 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/19 17:01:56 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		manage_prec(t_convlst *opt)
{
	if (opt->i_prec_arg != 0)
		opt->prec = (int)(opt->prec_arg->src);
	if ((opt->str)[0] == '-' && opt->prec > 0)
		opt->prec += 1;
	if (opt->prec > 0)
	{
		if (opt->conv == 's')
			opt->str = ft_strsub_free(opt->str, 0, opt->prec, 1);
		if (is_num_conv(opt->conv))
			while (ft_strlen(opt->str) < opt->prec)
				manage_z(opt, 1);
	}
	if (is_num_conv(opt->conv) && opt->prec == 0 && !ft_atoi(opt->str))
		if (opt->af != 1 || opt->conv == 'x' || opt->conv == 'X')
		{
			free(opt->str);
			opt->str = ft_strdup("");
			opt->af = 0;
		}
}

void		manage_af_pos(t_convlst *opt)
{
	if (opt->af == 1)
	{
		if ((opt->conv == 'o' || opt->conv == 'O') && (opt->str)[0] != '0')
			opt->str = ft_strjoin_free("0", opt->str, 2);
		if (opt->conv == 'x' || opt->conv == 'X')
		{
			if ((opt->str)[0] == '0' && (opt->str)[1] == '0')
				(opt->str)[1] = opt->conv;
			else
			{
				if (opt->conv == 'X')
					opt->str = ft_strjoin_free("0X", opt->str, 2);
				else if (ft_atoi_base_x(opt->str, opt->conv))
					opt->str = ft_strjoin_free("0x", opt->str, 2);
			}
		}
	}
	if (opt->pos > 0)
		if ((opt->conv == 'd' || opt->conv == 'i') && (opt->str)[0] != '-')
		{
			if (opt->pos == 1)
				opt->str = ft_strjoin_free(" ", opt->str, 2);
			else
				opt->str = ft_strjoin_free("+", opt->str, 2);
		}
}

void		manage_z(t_convlst *opt, int z)
{
	if (opt->prec >= 0 && ft_strlen(opt->str) >= opt->prec)
		z = 0;
	if ((opt->str)[0] == '-' && ft_isdigit((opt->str)[1]) && z)
	{
		(opt->str)[0] = '0';
		opt->str = ft_strjoin_free("-", opt->str, 2);
	}
	else
	{
		if (z)
			opt->str = ft_strjoin_free("0", opt->str, 2);
		else
			opt->str = ft_strjoin_free(" ", opt->str, 2);
	}
}

void		manage_opt(t_convlst **opt)
{
	if ((*opt)->conv == '%')
		(*opt)->str = ft_strdup("%");
	if ((*opt)->str == NULL)
		(*opt)->str = ft_strdup("(null)");
	else
	{
		manage_prec(*opt);
		if ((*opt)->z <= 0)
			manage_af_pos(*opt);
		if ((*opt)->i_fw_arg != 0)
			(*opt)->fw = (int)((*opt)->fw_arg->src);
		if ((*opt)->z == 1 && ((*opt)->pos == 2 && ((*opt)->str)[0] != '-'))
			(*opt)->fw -= 1;
		while (ft_strlen((*opt)->str) < (*opt)->fw)
		{
			if ((*opt)->z == -1)
				(*opt)->str = ft_strjoin_free((*opt)->str, " ", 1);
			else
				manage_z(*opt, (*opt)->z);
		}
		if ((*opt)->z == 1)
			manage_af_pos(*opt);
	}
	if ((*opt)->next)
		manage_opt(&((*opt)->next));
}
