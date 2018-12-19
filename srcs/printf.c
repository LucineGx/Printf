/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:27:13 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 18:44:54 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_arglst	*new_arg(t_arglst **arg, int n, void *src)
{
	t_arglst	*new_elem;
	t_arglst	*cursor;

	if (!(new_elem = (t_arglst*)ft_memalloc(sizeof(t_arglst))))
		return (NULL);
	new_elem->n = n;
	new_elem->src = src;
	if (n > 1)
	{
		cursor = *arg;
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = new_elem;
	}
	else
		*arg = new_elem;
	return (new_elem);
}

t_arglst	*get_fw_prec_arg(t_convlst *conv_start, t_arglst *arg_start)
{
	t_arglst	*arg;
	t_convlst	*conv;

	conv = conv_start;
	while (conv != NULL)
	{
		if (conv->i_fw_arg > 0)
		{
			arg = arg_start;
			while (arg && arg->n != conv->i_fw_arg)
				arg = arg->next;
			conv->fw_arg = arg;
		}
		if (conv->i_prec_arg > 0)
		{
			arg = arg_start;
			while (arg && arg->n != conv->i_prec_arg)
				arg = arg->next;
			conv->prec_arg = arg;
		}
		conv = conv->next;
	}
	return (arg_start);
}

t_arglst	*get_arg(t_convlst *conv_start, va_list ap)
{
	t_convlst	*cursor;
	t_arglst	*arg_start;
	int			n;

	cursor = conv_start;
	arg_start = NULL;
	n = 1;
	while (cursor != NULL)
	{
		if (cursor->i_fw_arg == -1)
			cursor->fw_arg = new_arg(&arg_start, n++, va_arg(ap, void*));
		if (cursor->i_prec_arg == -1)
			cursor->prec_arg = new_arg(&arg_start, n++, va_arg(ap, void*));
		if (cursor->conv != '%')
			cursor->arg = new_arg(&arg_start, n++, va_arg(ap, void*));
		cursor = cursor->next;
	}
	return (get_fw_prec_arg(conv_start, arg_start));
}

int			ft_printf(const char*src, ...)
{
	va_list		ap;
	t_convlst	*conv_lst;
	t_arglst	*arg_lst;
	int			ret;

//	t_convlst	*tmp;//

	conv_lst = global_pars(src);
	if (conv_lst)
	{
/*		tmp = conv_lst;
		while (tmp)
		{
			printf("\n---  CONVERSION  ---\n");
			printf("conv = %c\nstr = %s\nopt-len = %d\n", tmp->conv, tmp->str, tmp->opt_len);
			printf("FW - index = %d - val = %d\n", tmp->i_fw_arg, tmp->fw);
			printf("PREC - index = %d - val = %d\n", tmp->i_prec_arg, tmp->prec);
			printf("# = %d\nz = %d\npos = %d\nlm = %d\n\n", tmp->af, tmp->z, tmp->pos, tmp->lm);
			tmp = tmp->next;
		
		}
		return 1;*/
		va_start(ap, src);
		arg_lst = get_arg(conv_lst, ap);
		va_end(ap);
		manage_conv(conv_lst);
		manage_opt(&conv_lst);
	}
	ret = aff_list(get_str_to_print((char*)src, conv_lst), 1);
	if (conv_lst)
	{
		free_convlst(conv_lst);
		if (arg_lst)
			free_arglst(arg_lst);
	}
	return 0;
}

int		main(int av, char **ac)
{
//	char *test = ac[1];
	char *test = "%lls";

	printf("argument: %s\n", test);
	int ret = ft_printf(test);
	if (!ret)
		write(1, "NOTHING\n", 8);
	return 0;
}
