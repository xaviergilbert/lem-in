# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 14:54:36 by xgilbert          #+#    #+#              #
#    Updated: 2018/11/02 13:07:18 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./ft_atoi.c\
		./ft_bzero.c\
		./ft_strrev.c\
		./ft_isalnum.c\
		./ft_isalpha.c\
		./ft_isascii.c\
		./ft_isdigit.c\
		./ft_isprint.c\
		./ft_isspace.c\
		./ft_itoa.c\
		./ft_memalloc.c\
		./ft_memccpy.c\
		./ft_memchr.c\
		./ft_memcmp.c\
		./ft_memcpy.c\
		./ft_memdel.c\
		./ft_memmove.c\
		./ft_memset.c\
		./ft_putchar.c\
		./ft_putchar_fd.c\
		./ft_putendl.c\
		./ft_putendl_fd.c\
		./ft_putnbr.c\
		./ft_putnbr_fd.c\
		./ft_putstr.c\
		./ft_putstr_fd.c\
		./ft_strcat.c\
		./ft_strchr.c\
		./ft_strclr.c\
		./ft_strcmp.c\
		./ft_strcpy.c\
		./ft_strdel.c\
		./ft_strdup.c\
		./ft_strequ.c\
		./ft_striter.c\
		./ft_striteri.c\
		./ft_strjoin.c\
		./ft_strjoin1.c\
		./ft_strjoin2.c\
		./ft_strjoin3.c\
		./ft_strlcat.c\
		./ft_strlen.c\
		./ft_strmap.c\
		./ft_strmapi.c\
		./ft_strncat.c\
		./ft_strncmp.c\
		./ft_strncpy.c\
		./ft_strnequ.c\
		./ft_strnew.c\
		./ft_strnstr.c\
		./ft_strrchr.c\
		./ft_strsplit.c\
		./ft_strstr.c\
		./ft_strsub.c\
		./ft_strtrim.c\
		./ft_tolower.c\
		./ft_toupper.c\
		./ft_lstadd.c\
		./ft_lstdel.c\
		./ft_lstdelone.c\
		./ft_lstiter.c\
		./ft_lstmap.c\
		./ft_lstnew.c\
		./ft_print_words_table.c\
		./ft_putmaj.c\
		./ft_strndup.c\
		./ft_itoa_base.c\
		./ft_uitoa_base.c\
		./ft_putwchar.c\
		./ft_stockwchar.c\
		./ft_putwstr.c\
		./ft_stockwstr.c\
		./ft_wstrnew.c\
		./ft_char_to_str.c\
		./ft_putnstr.c\
		./ft_prsstr.c\
		./char_in_str.c\
		./ft_worth_zero.c\
		./ft_swap.c\
		./get_next_line.c\
		./ft_vabsolue.c\
		./ft_strcpy_until_c.c\
		./ft_recursive_factorial.c

RM = rm -f

OBJS = $(SRCS:.c=.o)

CC = gcc -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
	@echo "CREATION .o LIBFT"
	@gcc -c -Wall -Wextra -Werror $(SRCS)
	@echo "ASSEMBLAGE .o LIBFT"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@echo "SUPPRESSION .o LIBFT"
	@$(RM) $(OBJS)

fclean: clean
	@echo "SUPPRESSION .a LIBFT"
	@$(RM) $(NAME)

re: fclean all
