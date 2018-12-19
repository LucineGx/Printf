/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:02:39 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 17:03:49 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_free(char *s, unsigned int start, size_t len, int f)
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
	if (f)
	{
		free(s);
		s = NULL;
	}
	return (ret);
}
