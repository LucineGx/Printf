/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:44:35 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/19 20:14:01 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	free_convlst(t_convlst *cur)
{
	if (cur->str)
		free(cur->str);
	if (cur->next)
		free_convlst(cur->next);
	ft_memset(cur, 0, sizeof(t_convlst));
	free(cur);
	cur = NULL;
}

void		free_arglst(t_arglst *cur)
{
	cur->src = NULL;
	if (cur->next)
		free_arglst(cur->next);
	cur->next = NULL;
	free(cur);
	cur = NULL;
}

void		free_list(t_list *cur)
{
	if (cur->data)
		free(cur->data);
	cur->data = NULL;
	if (cur->next)
		free_list(cur->next);
	cur->next = NULL;
	free(cur);
	cur = NULL;
}

t_list		*get_str_to_print(char *src, t_convlst *opt)
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = NULL;
	if (!src[i])
		return (cur);
	if (!(cur = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (src[i] == '%')
	{
		cur->data = ft_strdup(opt->str);
		cur->nulchar = (opt->conv == 'c' && (char)(opt->arg->src) == 0) ? 1 : 0;
		if (cur->nulchar && cur->data)
			cur->data[ft_strlen(cur->data) - 1] = '\0';
		cur->next = get_str_to_print(&src[i + opt->opt_len], opt->next);
	}
	else
	{
		while (src[i] && src[i] != '%')
			i += 1;
		cur->data = ft_strsub(src, 0, i);
		cur->next = (src[i]) ? get_str_to_print(&src[i], opt) : NULL;
	}
	return (cur);
}

int			aff_list(t_list *first, int fd, char **s)
{
	int		ret;
	char	nullchar;
	t_list	*tmp;

//	write(1, "start AFF_LIST\n", 15);
	nullchar = 0;
	if (!first)
		return 0;
	ret = 0;
	tmp = first;
	while (tmp != NULL)
	{
/*		if (tmp->data)
		{
			write(fd, tmp->data, ft_strlen(tmp->data));
			ret += ft_strlen(tmp->data);
		}
		if (tmp->nulchar)
		{
			write(fd, &nullchar, 1);
			ret += 1;
		}*/

//		write(1, "while AFF_LIST\n", 15);

		if (tmp->data)
		{
			*s = ft_strjoin_free(*s, tmp->data, 1);
			ret += ft_strlen(tmp->data);
		}
		if (tmp->nulchar)
		{
			*s = ft_strjoin_free(*s, " ", 1);
			ret += 1;
		}
		
		tmp = tmp->next;
	}
	free_list(first);

	return (ret);
}
