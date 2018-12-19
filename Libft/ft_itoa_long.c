/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:37:58 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 15:58:45 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countchar(long n)
{
	int	count;

	if (n == -2147483648)
		return (11);
	if (n == 0 || n == -0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n = -n;
		count += 1;
	}
	while (n >= 1)
	{
		count += 1;
		n = n / 10;
	}
	return (count);
}

static char	*putinchar(long n, char *ret, int i)
{
	if (n == -0)
		ret[0] = '0';
	else if (n < 0)
	{
		ret[0] = '-';
		if (n == -2147483648)
		{
			ret[1] = '2';
			ret = putinchar(147483648, ret, i);
		}
		else
			ret = putinchar(-n, ret, i);
	}
	else
	{
		if (n > 9)
			ret = putinchar(n / 10, ret, i - 1);
		ret[i] = (n % 10) + 48;
	}
	return (ret);
}

char		*ft_itoa_long(long *n)
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
