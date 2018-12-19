/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detail_pars_more.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:40:52 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/12 20:27:27 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_index_field_width(char *s)
{
	int i;
	int val;

	i = 0;
	val = 0;
	while (s[++i])
	{
		if (s[i] == '*' && s[i - 1] != '.')
		{
			val = ft_atoi((const char*)&(s[i + 1]));
			if (val > 0)
			{
				while (ft_isdigit(s[i++]));
				if (s[i] == '$')
					return (val);
			}
			return -1;
		}
	}
	return 0;
}

int		get_field_width(char *s)
{
	int i;

	i = 0;
	while (s[++i])
	{
		if (ft_isdigit(s[i]) && s[i - 1] != '.' && s[i - 1] != '*')
		{
			if (s[i] != '0' && !ft_isdigit(s[i - 1]))
				return (ft_atoi((const char*)&(s[i])));
			else
			{
				while (ft_isdigit(s[i + 1]))
					i++;
			}
		}
	}
	return 0;
}

int		get_index_precision(char *s)
{
	int i;
	int val;

	i = 0;
	val = 0;
	while (s[++i])
	{
		if (s[i] == '*' && s[i - 1] == '.')
		{
			val = ft_atoi((const char*)&(s[i + 1]));
			if (val > 0)
			{
				while (ft_isdigit(s[++i]));
				if (s[i] == '$')
					return (val);
			}
			return -1;
		}
	}
	return 0;
}

int		get_precision(char *s)
{
	int i;

	i = 0;
	while (s[++i])
	{
		if (ft_isdigit(s[i]) && s[i - 1] == '.')
			return (ft_atoi((const char*)&(s[i])));
	}
	return 0;
}
