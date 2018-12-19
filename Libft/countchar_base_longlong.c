/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countchar_base_longlong.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:44:20 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 15:44:49 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		countchar_base_longlong(unsigned long long n, int base)
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
