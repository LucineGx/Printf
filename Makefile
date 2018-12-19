NAME = libftprintf.a

SRCS = atoi_base.c \
		convert_base.c \
		convert_base_char.c \
		convert_base_intmax_t.c \
		convert_base_long.c \
		convert_base_longlong.c \
		convert_base_short.c \
		convert_base_size_t.c \
		end.c \
		ft_itoa.c \
		ft_itoa_char.c \
		ft_itoa_intmaxt.c \
		ft_itoa_long.c \
		ft_itoa_longlong.c \
		ft_itoa_short.c \
		ft_itoa_sizet.c \
		ft_putchar.c \
		ft_strcat.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strjoinfree.c \
		ft_strlen.c \
		ft_strsub.c \
		get_str_to_print.c \
		manage_int.c \
		more_to_manage.c \
		pars_string.c \
		printf.c \

SRC = $(addprefix srcs/, $(SRCS))

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

%.o: %.c
		gcc -c $^ -o $@ -I include $(CFLAGS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
