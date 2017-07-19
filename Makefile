# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwragg <mwragg@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/30 15:32:31 by mwragg            #+#    #+#              #
#    Updated: 2017/01/15 11:36:32 by shuertas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC=	./fillit.c \
		./initialization.c \
		./check_tetri.c \
		./translate.c \
		./solver_init.c \
		./solver.c \
		./display.c

OBJ= $(SRC:.c=.o)

INCLUDES= -I fillit.h

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		@make -C Libft
		@gcc ./Libft/libft.a $(OBJ) -o $(NAME)

%.o: %.c
		@gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
		@make -C Libft clean
		@rm -rf $(OBJ)

fclean: clean
		@make -C Libft fclean
		@rm -rf $(NAME)

re: fclean all

fab:
		@cat extern_file.txt
