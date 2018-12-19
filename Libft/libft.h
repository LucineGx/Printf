/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:59:20 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 17:02:17 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_atoi(const char *s);

int		countchar_base(unsigned int n, int base);
int		countchar_base_char(unsigned char n, int base);
int		countchar_base_intmaxt(uintmax_t n, int base);
int		countchar_base_long(unsigned long n, int base);
int		countchar_base_longlong(unsigned long long n, int base);
int		countchar_base_short(unsigned short n, int base);
int		countchar_base_sizet(ssize_t n, int base);
char	*convert_base(unsigned int *n, char *base);
char	*convert_base_char(unsigned char *n, char *base);
char	*convert_base_intmaxt(uintmax_t *n, char *base);
char	*convert_base_long(unsigned long *n, char *base);
char	*convert_base_longlong(unsigned long long *n, char *base);
char	*convert_base_short(unsigned short *n, char *base);
char	*convert_base_sizet(ssize_t *n, char *base);
char	*ft_itoa(int n);
char	*ft_itoa_char(char *s);
char	*ft_itoa_intmaxt(intmax_t *n);
char	*ft_itoa_long(long *n);
char	*ft_itoa_longlong(long long *n);
char	*ft_itoa_short(short *n);
char	*ft_itoa_sizet(size_t *n);

int		ft_isdigit(int c);
int		ft_iswhitespace(int c);

void	*ft_memset(void *ptr, int val, size_t size);
void	*ft_memalloc(size_t size);

int		ft_strlen(const char *s);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
char	*ft_strjoin_free(char *begin, char *end, int opt);
char	*ft_strsub(char *s, unsigned int start, size_t len);
char	*ft_strsub_free(char *s, unsigned int start, size_t len, int f);

#endif
