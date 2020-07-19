# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xgilbert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 19:00:53 by xgilbert          #+#    #+#              #
#    Updated: 2019/01/12 19:06:37 by xgilbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FONCTIONS = ./srcs/check_errors.c ./srcs/check_errors2.c ./srcs/display.c\
			./srcs/get_info.c ./srcs/main.c ./srcs/parsing.c\
			./srcs/path_finding.c ./srcs/path_finding2.c\
			./srcs/sort_path.c ./srcs/elimination.c ./srcs/ants_going_in.c\
			./srcs/building.c ./srcs/free_all.c ./srcs/ft_isnumber.c\
			./srcs/modif_matrix.c ./srcs/matrix_lst.c

LIBFT = ./libft/libftprintf.a

RM = rm -rf

CURRENT_DIR = $(shell pwd)

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(LIBFT):
	@echo "COMPILATION LIBFT"
	@make -C libft

$(NAME): $(LIBFT) $(FONCTIONS) $(OBJS)
	@echo "COMPILAGE LEM_IN"
	@gcc $(FLAGS) -o $(NAME) $(FONCTIONS) $(LIBFT)

clean:
	@cd ./libft && make clean

fclean: clean
	@echo "SUPPRESSION EXECUTABLES"
	@$(RM) $(NAME)
	@cd ./libft/ && make fclean

re: fclean all
