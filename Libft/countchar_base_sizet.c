/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countchar_base_sizet.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:46:33 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 15:47:38 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		countchar_base_sizet(ssize_t n, int base)
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
