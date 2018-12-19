/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 19:44:26 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/17 19:44:29 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	free_convlst(t_convlst *cur)
{
	if (cur->str)
		free(cur->str);
	cur->str = NULL;
	cur->arg = NULL;
	cur->fw_arg = NULL;
	if (cur->next)
		free_convlst(cur->next);
	cur->next = NULL;
	free(cur);
	cur = NULL;
}

void	free_arglst(t_arglst *cur)
{
	cur->src = NULL;
	if (cur->next)
		free_arglst(cur->next);
	cur->next = NULL;
	free(cur);
	cur = NULL;
}

void	free_list(t_list *cur)
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
