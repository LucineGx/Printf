/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_to_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 19:19:46 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/17 17:53:18 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	manage_z(t_convlst **opt, int z)
{
	if ((*opt)->prec >= 0 && ft_strlen((*opt)->str) >= (*opt)->prec)
		z = 0;
	if (((*opt)->str)[0] == '-' && ft_isdigit(((*opt)->str)[1]) && z)
	{
		((*opt)->str)[0] = '0';
		(*opt)->str = joinfree("-", (*opt)->str, 2);
	}
	else
		(*opt)->str = joinfree((z) ? ("0") : (" "), (*opt)->str, 2);
}
