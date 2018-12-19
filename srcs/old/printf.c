/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 18:07:54 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/16 20:16:14 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_arglst	*new_arg(t_arglst **arg, int n, void *src)
{
	t_arglst	*new_elem;
	t_arglst	*tmp;

	if (!(new_elem = (t_arglst*)malloc(sizeof(t_arglst))))
		return (NULL);
	new_elem->n = n;
	new_elem->src = src;
	new_elem->next = NULL;
	if (n > 1)
	{
		tmp = *arg;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
	else
		(*arg = new_elem);
	return (new_elem);
}

t_arglst	*get_arg(t_convlst **convs, va_list ap)
{
	t_convlst	*tmp;
	t_arglst	*ret;
	int			n;

	tmp = *convs;
	ret = NULL;
	n = 1;
	while (tmp != NULL)
	{
		if (tmp->i_fw_arg == -1)
			tmp->fw_arg = new_arg(&ret, n++, va_arg(ap, void*));
		if (tmp->conv != '%')
			tmp->arg = new_arg(&ret, n++, va_arg(ap, void*));
		tmp = tmp->next;
	}
	tmp = *convs;
	while (tmp != NULL)
	{
		if (tmp->i_fw_arg > 0)
			while (ret->n != tmp->i_fw_arg)
				ret = ret->next;
		tmp->fw_arg = (tmp->i_fw_arg > 0) ? ret : tmp->fw_arg;
		tmp = tmp->next;
	}
	return (((*convs)->i_fw_arg == -1) ? ((*convs)->fw_arg) : ((*convs)->arg));
}

int			aff_list(t_list *first)
{
	int		ret;
	char	nullchar;
	t_list	*tmp;

	nullchar = 0;
	if (!first)
		return (0);
	ret = 0;
	tmp = first;
	while (tmp != NULL)
	{
		if (tmp->data)
		{
			write(1, tmp->data, ft_strlen(tmp->data));
			ret += ft_strlen(tmp->data);
		}
		if (tmp->nulchar)
		{
			write(1, &nullchar, 1);
			ret += 1;
		}
		tmp = tmp->next;
	}
	free_list(first);
	return (ret);
}

int			ft_printf(const char *src, ...)
{
	va_list		ap;
	int			ret;
	t_convlst	*conv_lst;
	t_arglst	*arg_lst;

	conv_lst = global_pars(src);
	va_start(ap, src);
	if (conv_lst)
	{
		arg_lst = get_arg(&conv_lst, ap);
		va_end(ap);
		manage_conv(&conv_lst);
		manage_opt(&conv_lst);
	}
	ret = aff_list(get_str_to_print((char*)src, conv_lst));
	if (conv_lst)
	{
		free_convlst(conv_lst);
		if (arg_lst)
			free_arglst(arg_lst);
	}
	return (ret);
}
