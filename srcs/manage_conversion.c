/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:57:39 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 16:43:42 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.c"

char	*manage_ptr(void *src, t_convlst *conv)
{
	char *ret;

	(void)conv;
	ret = convert_base_long((unsigned long*)src, create_base('x'));
	ret = ft_strjoin_free("0x", ret, 2);
	return ret;
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
	unsigned long int	*tmp;

	if (opt->conv == 'D')
		return (ft_itoa_long((long int*)src));
	if (opt->conv == 'O' || opt->conv == 'U')
	{
		tmp = (unsigned long int*)src;
		return (convert_base_long(tmp, create_base(opt->conv + 32)));
	}
	return (NULL);
}

char	*manage_int_to_convert(void *src, t_convlst *opt)
{
	char	*base;

	base = create_base(opt->conv);
	if (opt->lm == LCHAR)
		return (convert_base_char((unsigned char*)src, base));
	if (opt->lm == LSINT)
		return (convert_base_short((unsigned short*)src, base));
	if (opt->lm == LLLINT)
		return (convert_base_longlong((unsigned long long*)src, base));
	if (opt->lm == LLINT)
		return (convert_base_long((unsigned long*)src, base));
	if (opt->lm == LSIZET)
		return (convert_base_sizet((ssize_t*)src, base));
	if (opt->lm == LINTMAXT)
		return (convert_base_intmaxt((uintmax_t*)src, base));
	if (opt->lm == -1 || opt->lm == 0)
		return (convert_base((unsigned int*)src, base));
	return NULL;
}

void	manage_conv(t_convlst *conv)
{
	char	*to_compare;
	char	*(*funptr[14])(void*, t_convlst*);
	int		i;

	to_compare = "sSpdDioOuUxXcC";
	funptr[0] = &ft_strdup_void;
	funptr[1] = &ft_strdup_void;
	funptr[2] = &manage_ptr;
	funptr[3] = &manage_int;
	funptr[4] = &manage_maj_int;
	funptr[5] = &manage_int;
	funptr[6] = &manage_int_to_convert;
	funptr[7] = &manage_maj_int;
	funptr[8] = &manage_int_to_convert;
	funptr[9] = &manage_maj_int;
	funptr[10] = &manage_int_to_convert;
	funptr[11] = &manage_int_to_convert;
	funptr[12] = &ft_putchar_void;
	funptr[13] = &ft_putchar_void;
	i = -1;
	while (to_compare[++i])
		if (to_compare[i] == conv->conv)
			conv->str = funptr[i](&(conv->arg->src), conv);
	if (conv->next)
		manage_conv(conv->next);
}
