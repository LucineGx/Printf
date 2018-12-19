/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:37:58 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 15:58:12 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countchar(size_t n)
{
	int	count;

	if (n == 0 || n == -0)
		return (1);
	count = 0;
	while (n >= 1)
	{
		count += 1;
		n = n / 10;
	}
	return (count);
}

static char	*putinchar(size_t n, char *ret, int i)
{
	if (n > 9)
		ret = putinchar(n / 10, ret, i - 1);
	ret[i] = (n % 10) + 48;
	return (ret);
}

char		*ft_itoa_sizet(size_t *n)
{
	char	*ret;
	int		i;

	i = countchar(*n);
	if ((ret = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	ret[i] = '\0';
	ret = putinchar(*n, ret, i - 1);
	return (ret);
}
