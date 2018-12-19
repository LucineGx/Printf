/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:06:29 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/19 17:07:59 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*create_base(char opt)
{
	if (opt == 'o')
		return (ft_strdup("01234567"));
	if (opt == 'x')
		return (ft_strdup("0123456789abcdef"));
	if (opt == 'X')
		return (ft_strdup("0123456789ABCDEF"));
	if (opt == 'u')
		return (ft_strdup("0123456789"));
	return (NULL);
}

int		is_num_conv(char c)
{
	char	*to_comp;
	int		i;

	to_comp = "xXdDioOuU";
	i = 0;
	while (to_comp[i])
	{
		if (to_comp[i] == c)
			return 1;
		i++;
	}
	return 0;
}
