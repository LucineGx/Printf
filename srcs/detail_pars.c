/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detail_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:02:22 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/13 15:48:14 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_conversion(t_convlst *current, const char *s, int pos)
{
	int		i;
	char	*conv_char;
	int		j;

	i = pos;
	conv_char = "sSpdDioOuUxXcC%";
	while (s[++i])
	{
		j = 0;
		while (conv_char[j])
		{
			if (s[i] == conv_char[j++])
			{
				current->conv = s[i];
				current->opt_len = i - pos + 1;
				current->str = ft_strsub((char*)s, pos, (i - pos + 1));
				if (current->str)
					return 1;
				else 
					return 0;
			}
		}
	}
	return 0;
}

int		get_other_converted_types(char *s)
{
	int i;
	int tmp;
	int ret;

	i = 0;
	ret = 0;
	while (s[++i])
	{
		tmp = 0;
		if (s[i] == 'h')
			tmp = (s[i + 1] == 'h') ? LCHAR : LSINT;
		else if (s[i] == 'l')
			tmp = (s[i + 1] == 'l') ? LLLINT : LLINT;
		else if (s[i] == 'j')
			tmp = LINTMAXT;
		else if (s[i] == 'z')
			tmp = LSIZET;
		if (tmp != 0 && ret != 0)
			return -1;
		else if (ret == 0)
			ret = tmp;
		if (tmp == LCHAR || tmp == LLLINT)
			i++;
	}
	return (ret);
}

int		get_sharp_opt(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == '#')
			return 1;
	}
	return 0;
}

int		get_zero_minus_opt(char *s)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s[++i])
	{
		if (s[i] == '0' && !ft_isdigit(s[i - 1]) && ret != -1)
			ret = 1;
		else if (s[i] == '-')
			ret = -1;
	}
	return (ret);
}

int		get_space_plus_opt(char *s)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s[++i])
	{
		if (s[i] == ' ' && ret != 2)
			ret = 1;
		else if (s[i] == '+')
			ret = 2;
	}
	return (ret);
}
