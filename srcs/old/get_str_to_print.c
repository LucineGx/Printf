/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_to_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 12:44:02 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/17 19:59:57 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		manage_prec(t_convlst **opt)
{
	char	*to_comp;
	int		i;

	to_comp = "xXdDioOuU";
	i = -1;
	if (((*opt)->str)[0] == '-' && (*opt)->prec > 0)
		(*opt)->prec += 1;
	if ((*opt)->prec > 0)
	{
		if ((*opt)->conv == 's')
			(*opt)->str = ft_strsub_free((*opt)->str, 0, (*opt)->prec, 1);
		while (to_comp[++i])
			if (to_comp[i] == (*opt)->conv)
				while (ft_strlen((*opt)->str) < (*opt)->prec)
					manage_z(opt, 1);
	}
	i = 0;
	while ((*opt)->prec == 0 && ((*opt)->af != 1 || i < 2) && to_comp[i])
		if (to_comp[i++] == (*opt)->conv && !satoi((*opt)->str))
		{
			free((*opt)->str);
			(*opt)->str = ft_strdup("");
			(*opt)->af = 0;
		}
}

void		manage_af__pos(t_convlst **op)
{
	if ((*op)->af == 1)
	{
		if ((*op)->conv == 'o' && ((*op)->str)[0] != '0')
			(*op)->str = joinfree("0", (*op)->str, 2);
		if ((*op)->conv == 'O' && ((*op)->str)[0] != '0')
			(*op)->str = joinfree("0", (*op)->str, 2);
		if ((*op)->conv == 'x')
		{
			if (((*op)->str)[0] == '0' && ((*op)->str)[1] == '0')
				((*op)->str)[1] = 'x';
			else if (ft_atoi_base_x((*op)->str, (*op)->conv))
				(*op)->str = joinfree("0x", (*op)->str, 2);
		}
		if ((*op)->conv == 'X')
		{
			if (((*op)->str)[0] == '0' && ((*op)->str)[1] == '0')
				((*op)->str)[1] = 'X';
			else
				(*op)->str = joinfree("0X", (*op)->str, 2);
		}
	}
	if ((*op)->pos > 0)
		if (((*op)->conv == 'd' || (*op)->conv == 'i') && (*op)->str[0] != '-')
			(*op)->str = joinfree(((*op)->pos == 1) ? " " : "+", (*op)->str, 2);
}

void		manage_opt(t_convlst **opt)
{
	if ((*opt)->conv == '%')
		(*opt)->str = ft_strdup("%");
	if ((*opt)->str == NULL)
		(*opt)->str = ft_strdup("(null)");
	else
	{
		manage_prec(opt);
		if ((*opt)->z <= 0)
			manage_af__pos(opt);
		if ((*opt)->i_fw_arg != 0)
			(*opt)->fw = (int)((*opt)->fw_arg->src);
		if ((*opt)->z == 1 && ((*opt)->pos == 2 && ((*opt)->str)[0] != '-'))
			(*opt)->fw -= 1;
		while (ft_strlen((*opt)->str) < (*opt)->fw)
		{
			if ((*opt)->z == -1)
				(*opt)->str = joinfree((*opt)->str, " ", 1);
			else
				manage_z(opt, (*opt)->z);
		}
		if ((*opt)->z == 1)
			manage_af__pos(opt);
	}
	if ((*opt)->next)
		manage_opt(&((*opt)->next));
}

void		manage_conv(t_convlst **opt)
{
	char	*to_compare;
	char	*(*funptr[14])(void*, t_convlst*);
	int		i;

	to_compare = "sSpdDioOuUxXcC";
	funptr[0] = &ft_strdup_void;
	funptr[1] = funptr[0];
	funptr[2] = &manage_ptr;
	funptr[3] = &manage_int;
	funptr[4] = &manage_maj_int;
	funptr[5] = funptr[3];
	funptr[6] = &manage_int_to_convert;
	funptr[7] = funptr[4];
	funptr[8] = funptr[6];
	funptr[9] = funptr[4];
	funptr[10] = funptr[6];
	funptr[11] = funptr[6];
	funptr[12] = &ft_putchar_void;
	funptr[13] = funptr[12];
	i = -1;
	while (to_compare[++i])
		if (to_compare[i] == (*opt)->conv)
			(*opt)->str = funptr[i](&((*opt)->arg->src), *opt);
	if ((*opt)->next)
		manage_conv(&((*opt)->next));
}

t_list		*get_str_to_print(char *src, t_convlst *opt)
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = NULL;
	if (!src[i])
		return (cur);
	if (!(cur = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (src[i] == '%')
	{
		cur->data = ft_strdup(opt->str);
		cur->nulchar = (opt->conv == 'c' && (char)(opt->arg->src) == 0) ? 1 : 0;
		if (cur->nulchar && cur->data)
			cur->data[ft_strlen(cur->data) - 1] = '\0';
		cur->next = get_str_to_print(&src[i + opt->opt_len], opt->next);
	}
	else
	{
		while (src[i] && src[i] != '%')
			i += 1;
		cur->data = ft_strsub_free(src, 0, i, 0);
		cur->next = (src[i]) ? get_str_to_print(&src[i], opt) : NULL;
	}
	return (cur);
}
