/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 19:44:59 by lgaveria          #+#    #+#             */
/*   Updated: 2017/10/17 19:46:53 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*manage_int_to_convert(void *src, t_convlst *opt)
{
	if (opt->lm == LCHAR)
		return (convert_base_char((unsigned char*)src, opt->conv));
	if (opt->lm == LSINT)
		return (convert_base_short((unsigned short int*)src, opt->conv));
	if (opt->lm == LLLINT)
		return (convert_base_longlong((unsigned long long int*)src, opt->conv));
	if (opt->lm == LLINT)
		return (convert_base_long((unsigned long int*)src, opt->conv));
	if (opt->lm == LSIZET)
		return (convert_base_sizet((ssize_t*)src, opt->conv));
	if (opt->lm == LINTMAXT)
		return (convert_base_intmaxt((uintmax_t*)src, opt->conv));
	if (opt->lm == -1 || opt->lm == 0)
		return (convert_base((unsigned int*)src, opt->conv));
	return (NULL);
}

char	*manage_int(void *src, t_convlst *opt)
{
	if (opt->lm == LCHAR)
		return (ft_itoa_char((char*)src));
	if (opt->lm == LSINT)
		return (ft_itoa_short((short int*)src));
	if (opt->lm == LLLINT)
		return (ft_itoa_longlong((long long int*)src));
	if (opt->lm == LLINT)
		return (ft_itoa_long((long int*)src));
	if (opt->lm == LSIZET)
		return (ft_itoa_sizet((size_t*)src));
	if (opt->lm == LINTMAXT)
		return (ft_itoa_intmaxt((intmax_t*)src));
	if (opt->lm == -1 || opt->lm == 0)
		return (ft_itoa_int((int*)src));
	return (NULL);
}

char	*manage_maj_int(void *src, t_convlst *opt)
{
	if (opt->conv == 'D')
		return (ft_itoa_long((long int*)src));
	if (opt->conv == 'O' || opt->conv == 'U')
		return (convert_base_long((unsigned long int*)src, opt->conv + 32));
	return (NULL);
}

char	*manage_ptr(void *src, t_convlst *opt)
{
	char *ret;

	(void)opt;
	ret = convert_base_long((unsigned long int*)src, 'x');
	ret = joinfree("0x", ret, 2);
	return (ret);
}
