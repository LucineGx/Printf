/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 17:15:59 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 15:48:55 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*convert_base_char(unsigned char *n, char *base)
{
	char			*ret;
	int				i;

	i = countchar_base_char(*n, ft_strlen(base));
	if (!(ret = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret[i] = '\0';
	while (--i >= 0)
	{
		ret[i] = base[*n % ft_strlen(base)];
		*n /= ft_strlen(base);
	}
	return (ret);
}
