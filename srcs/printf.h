/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaveria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:27:58 by lgaveria          #+#    #+#             */
/*   Updated: 2018/12/19 18:18:20 by lgaveria         ###   ########.fr       */
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

#define RESET  "\x1B[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"

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

int				ft_printf(char **s, const char *toprint, ...);
t_convlst		*global_pars(const char *str);
int				precise_pars(t_convlst *current, const char *s, int i);
t_arglst		*get_arg(t_convlst *conv_start, va_list ap);
t_arglst		*get_fw_prec_arg(t_convlst *conv_start, t_arglst *arg_start);
void			manage_conv(t_convlst *conv);
void			manage_opt(t_convlst **opt);
t_list			*get_str_to_print(char *src, t_convlst *opt);
int				aff_list(t_list *first, int fd, char **s);

int				get_conversion(t_convlst *current, const char *s, int pos);
int				get_other_converted_types(char *s);
int				get_sharp_opt(char *s);
int				get_zero_minus_opt(char *s);
int				get_space_plus_opt(char *s);
int				get_index_field_width(char *s);
int				get_field_width(char *s);
int				get_index_precision(char *s);
int				get_precision(char *s);

char			*manage_ptr(void *src, t_convlst *conv);
char			*manage_int(void *src, t_convlst *opt);
char			*manage_maj_int(void *src, t_convlst *opt);
char			*manage_int_to_convert(void *src, t_convlst *opt);
char			*ft_strdup_void(void *s, t_convlst *conv);
char			*ft_putchar_void(void *src, t_convlst *opt);

void			manage_prec(t_convlst *opt);
void			manage_af_pos(t_convlst *opt);
void			manage_z(t_convlst *opt, int z);

t_convlst		*new_conv(t_convlst **lst_start);
t_arglst		*new_arg(t_arglst **arg, int n, void *src);

void			free_convlst(t_convlst *cur);
void			free_arglst(t_arglst *cur);
void			free_list(t_list *cur);

char			*create_base(char opt);
int				is_num_conv(char c);
int				ft_atoi_base_x(char *s, char b);

#endif
