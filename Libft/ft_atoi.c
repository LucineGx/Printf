/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:53:38 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/12 19:02:36 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int i;
	int signe;
	int nb;

	if (!s)
		return 0;
	i = 0;
	signe = 1;
	nb = 0;
	while (ft_iswhitespace(s[i]))
		i += 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			signe = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (signe * nb);
}
