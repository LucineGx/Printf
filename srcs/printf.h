/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:27:58 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/18 18:44:46 by lgaveria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

#ifndef PRINTF_H

# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>
# include "../Libft/libft.h"
# define LCHAR 1
# define LSINT 2
# define LLLINT 3
# define LLINT 4
# define LINTMAXT 5
# define LSIZET 6

typedef struct	s_list
{
	char			*data;
	char			nulchar;
	struct s_list	*next;
}				t_list;

typedef struct	s_arglst
{
	int				n;
	void			*src;
	struct s_arglst	*next;
}				t_arglst;

typedef struct	s_convlst
{
	char				conv; /* CONVERSION  */
	char				*str; /* STRING COMPLETE  */
	int					opt_len; /* TAILLE DE LA STRING  */
	t_arglst			*arg; /* ARGUMENT CORRESPONDANT */
	int					i_fw_arg; /* INDEX ARGUMENT LARGEUR DE CHAMPS*/
	t_arglst			*fw_arg; /* ARGUMENT LARGEUR DE CHAMPS */
	int					fw; /* LARGEUR DE CHAMPS */
	int					i_prec_arg; /* INDEX ARGUMENT PRECISION */
	t_arglst			*prec_arg; /* ARGUMENT PRECISION */
	int					prec; /*PRECISION */
	int					af; /* CHANGEMENT DE FORME # */
	int					z; /* REMPLISSAGE 0 ou ALIGNEMENT GAUCHE -  */
	int					pos; /* AFFICHAGE AVANT NOMBRE SIGNE */
	int					lm; /* TYPES SUPPLEMENTAIRES*/
	struct s_convlst	*next;
}				t_convlst;

int				ft_printf(const char *toprint, ...);
t_convlst		*global_pars(const char *str);
t_list			*get_str_to_print(char *src, t_convlst *opt);
void			manage_conv(t_convlst *opt);
void			manage_opt(t_convlst **opt);
void			manage_z(t_convlst *o, int z);
char			*manage_int(void *src, t_convlst *opt);
char			*manage_int_to_convert(void *src, t_convlst *opt);
char			*manage_maj_int(void *src, t_convlst *opt);
char			*manage_ptr(void *src, t_convlst *opt);
void			free_convlst(t_convlst *cur);
void			free_arglst(t_arglst *cur);
void			free_list(t_list *cur);
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strdup_void(void *s, t_convlst *opt);
char			*ft_strsub_free(char *s, unsigned int i, size_t len, int yfree);
int				ft_atoi_base_x(char *s, char b);
char			*ft_itoa(int n);
char			*ft_itoa_int(int *n);
char			*ft_itoa_char(char *n);
char			*ft_itoa_short(short *n);
char			*ft_itoa_long(long *n);
char			*ft_itoa_sizet(size_t *n);
char			*ft_itoa_intmaxt(intmax_t *n);
char			*ft_itoa_longlong(long long *n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);
char			*create_base(char opt);
char			*ft_putchar_void(void *src, t_convlst *opt);
int				satoi(const char *str);
int				count_char(unsigned int n, int base);
int				get_conversion(t_convlst *current, const char *s, int i);
int				get_index_field_width(char *s);
int				get_field_width(char *s);
int				get_index_precision(char *s);
int				get_precision(char *s);
int				get_sharp_opt(char *s);
int				get_zero_minus_opt(char *s);
int				get_space_plus_opt(char *s);
int				get_other_converted_types(char *s);
int				is_num_conv(char c);
int				aff_list(t_list *first, int fd);


#endif
