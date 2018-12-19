/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:43:44 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 16:43:26 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strdup_void(void *s, t_convlst *conv)
{
	char	**tmp;
	char	*src;
	char	*dest;
	int		i;

	(void)conv;
	tmp = (char**)s;
	src = *tmp;
	if (!src)
		return (NULL);
	if ((dest = malloc(sizeof(char) * ft_strlen(src) + 1)) == 0)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

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
