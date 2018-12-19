/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:24:20 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/13 17:37:29 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *begin, char *end, int opt)
{
	char *ret;

	if (begin == NULL && end == NULL)
		return (NULL);
	if (begin == NULL || end == NULL)
		ret = ((begin == NULL) ? ft_strdup(end) : ft_strdup(begin));
	else
	{
		ret = malloc(sizeof(char) * (ft_strlen(begin) + ft_strlen(end) + 1));
		if (!ret)
			return (NULL);
		ret = ft_strcpy(ret, begin);
		ret = ft_strcat(ret, end);
	}
	if ((opt == 1 || opt == 3) && begin != NULL)
		free(begin);
	if ((opt == 2 || opt == 3) && end != NULL)
		free(end);
	return (ret);
}
