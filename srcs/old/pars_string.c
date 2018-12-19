/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 11:42:23 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/16 20:49:32 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_convlst	*new_conv(t_convlst **conv, t_convlst *tmp)
{
	t_convlst	*new_elem;

	if (!(new_elem = (t_convlst*)malloc(sizeof(t_convlst))))
		return (NULL);
	new_elem->conv = 0;
	new_elem->str = NULL;
	new_elem->arg = NULL;
	new_elem->i_fw_arg = 0;
	new_elem->fw_arg = NULL;
	new_elem->fw = 0;
	new_elem->af = 0;
	new_elem->z = 0;
	new_elem->pos = 0;
	new_elem->prec = -1;
	new_elem->next = NULL;
	new_elem->opt_len = 0;
	new_elem->lm = 0;
	*conv = (tmp == NULL) ? new_elem : *conv;
	if (tmp == NULL)
		return (new_elem);
	if (tmp != NULL)
		while (tmp->next != NULL)
			tmp = tmp->next;
	tmp->next = new_elem;
	return (new_elem);
}

int			some_pars(t_convlst **current, const char *str, int i)
{
	int tmp;

	tmp = 0;
	if (str[i] == '#')
		(*current)->af = 1;
	if (str[i] == '+' || (str[i] == ' ' && (*current)->pos != 2))
		(*current)->pos = (str[i] == '+') ? 2 : 1;
	if (str[i] == '-' || (str[i] == '0' && (*current)->z != -1))
		(*current)->z = (str[i] == '-') ? -1 : 1;
	if (str[i] == 'h')
		tmp = (str[i + 1] == 'h') ? LCHAR : LSINT;
	else if (str[i] == 'l')
		tmp = (str[i + 1] == 'l') ? LLLINT : LLINT;
	else if (str[i] == 'j')
		tmp = LINTMAXT;
	else if (str[i] == 'z')
		tmp = LSIZET;
	if (tmp != 0 && (*current)->lm != 0)
		(*current)->lm = -1;
	else if ((*current)->lm == 0)
		(*current)->lm = tmp;
	if (tmp != 0)
		i += (tmp == LCHAR || tmp == LLLINT) ? 2 : 1;
	return (i);
}

int			is_conversion_char(char c)
{
	char	*to_compare;
	int		i;

	to_compare = "sSpdDioOuUxXcC%";
	i = 0;
	while (to_compare[i])
	{
		if (c == to_compare[i])
			return (1);
		i++;
	}
	return (0);
}

void		precise_pars(t_convlst *current, const char *s, int i_init)
{
	int		i;

	i = i_init + 1;
	while (s[i] && current->conv == 0)
	{
		i = some_pars(&current, s, i);
		current->conv = (is_conversion_char(s[i])) ? s[i] : 0;
		if (ft_isdigit(s[i]))
			current->fw = satoi(&(s[i]));
		if (s[i] == '.')
			current->prec = satoi(&(s[i + 1]));
		if (s[i] == '*')
		{
			current->i_fw_arg = (satoi(&(s[i + 1]))) ? satoi(&(s[i + 1])) : -1;
			if (s[i + count_char(current->i_fw_arg, 10) + 1] != '$')
				current->i_fw_arg = -1;
		}
		if (ft_isdigit(s[i]) || s[i] == '.' || s[i] == '*')
			while (s[i + 1] && ft_isdigit(s[i + 1]))
				i++;
		i++;
	}
	current->opt_len += i - i_init;
}

t_convlst	*global_pars(const char *str)
{
	int			i;
	t_convlst	*convs;
	t_convlst	*tmp;

	i = 0;
	convs = NULL;
	if (!ft_strlen(str))
		return (NULL);
	while (str[i])
	{
		tmp = convs;
		if (str[i] == '%')
		{
			tmp = new_conv(&convs, tmp);
			precise_pars(tmp, str, i);
			i += tmp->opt_len - 1;
		}
		i += 1;
	}
	return (convs);
}
