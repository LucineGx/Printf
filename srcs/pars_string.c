/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:35:19 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/12 20:29:04 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_convlst	*new_conv(t_convlst **lst_start)
{
	t_convlst	*new_elem;
	t_convlst	*cursor;

	if ((new_elem = (t_convlst*)ft_memalloc(sizeof(t_convlst))) == 0)
		return (NULL);
	if (*lst_start == NULL)
		*lst_start = new_elem;
	else
	{
		cursor = *lst_start;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new_elem;
	}
	return (new_elem);
}

int		precise_pars(t_convlst *current, const char *s, int i)
{
	if (!get_conversion(current, s, i)){
		return 0;write(1, "NO CONV\n", 8);}
	current->i_fw_arg = get_index_field_width(current->str);
	current->fw = get_field_width(current->str);
	current->i_prec_arg = get_index_precision(current->str);//
	current->prec = get_precision(current->str);//
	current->af = get_sharp_opt(current->str);
	current->z = get_zero_minus_opt(current->str);
	current->pos = get_space_plus_opt(current->str);
	current->lm = get_other_converted_types(current->str);
	return 1;
}

t_convlst	*global_pars(const char *str)
{
	int			i;
	t_convlst	*lst_start;
	t_convlst	*last;

	i = 0;
	lst_start = NULL;
	if (!ft_strlen(str))
		return NULL;
	while (str[i])
	{
		if (str[i] == '%')
		{
			last = new_conv(&lst_start);
			if (!precise_pars(last, str, i))
			{
				free_convlst(lst_start);
				return NULL;
			}
			i += last->opt_len - 1;
		}
		i++;
	}
	return (lst_start);
}
