/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:16:40 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/12 14:33:40 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_putchar_void(void *src, t_convlst *opt)
{
	char *c;
	char *tmp;

	(void)opt;
	tmp = (char*)src;
	c = malloc(sizeof(char) * 2);
	c[0] = *tmp;
	c[1] = '\0';
	return (c);
}
