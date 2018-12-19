/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countchar_base_intmaxt.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:40:26 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 15:41:26 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		countchar_base_intmaxt(uintmax_t n, int base)
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
