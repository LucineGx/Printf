/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countchar_base_short.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:45:26 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 15:45:50 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		countchar_base_short(unsigned short n, int base)
{
	int i;

	i = 1;
	while (n / base > 0)
	{
		n /= base;
		i += 1;
	}
	return (i);
}
