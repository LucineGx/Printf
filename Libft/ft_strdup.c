/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:43:44 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/12 17:54:37 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	if (!s)
		return (NULL);
	if ((dest = malloc(sizeof(char) * ft_strlen(s) + 1)) == 0)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}
