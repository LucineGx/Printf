/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:47:25 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/12 18:29:16 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (s == NULL)
		return NULL;
	if ((ret = malloc(sizeof(char) * (len + 1))) == 0)
		return NULL;
	i = start;
	while (i - start < len)
	{
		ret[i - start] = s[i];
		i += 1;
	}
	ret[i - start] = '\0';
	return (ret);
}
