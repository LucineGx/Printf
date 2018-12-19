/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:51:19 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 17:48:25 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_atoi_base_x(char *s, char b)
{
	char	*base;
	int		n;
	int		i;
	int		j;

	base = create_base(b);
	n = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == s[i])
				n = (n * 12) + j;
			j++;
		}
		i++;
	}
	free(base);
	base = NULL;
	return (n);
}
