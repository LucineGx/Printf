/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countchar_base_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:41:48 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 15:43:42 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		countchar_base_long(unsigned long n, int base)
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
