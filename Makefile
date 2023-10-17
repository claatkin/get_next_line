# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: claatkin <claatkin@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 16:42:02 by claatkin          #+#    #+#              #
#    Updated: 2023/10/17 16:43:43 by claatkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c get_next_line_utils.c 
	
OBJ = $(SRC:%.c=%.o)
NAME = get_next_line.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc

RM = rm -f

all: $(NAME)

${NAME}: $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
			$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re