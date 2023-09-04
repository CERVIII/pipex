# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 10:42:42 by pcervill          #+#    #+#              #
#    Updated: 2023/09/04 10:44:49 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address -g3

SRC_DIR = ./src

SRCS = pipex.c

OBJS = $(addprefix $(SRC_DIR)/, ${SRCS:.c=.o})

NAME = pipex

LIBFT_PATH = ./include/libft/

all:		$(NAME)
			@echo " \033[32m[ OK ] | Pipex ready!\033[0m"

$(NAME):	$(OBJS)
			@echo " \033[33m[ .. ] | Compiling libft..\033[0m"
			make bonus -C $(LIBFT_PATH)
			@echo " \033[32m[ OK ] | Libft ready!\033[0m"
			@echo " \033[33m[ .. ] | Compiling pipex..\033[0m"
			$(CC) -L $(LIBFT_PATH) -l ft $(CFLAGS) $(OBJS)  -o $(NAME)

clean:
			make clean -C $(LIBFT_PATH)
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)
			make fclean -C $(LIBFT_PATH)
			@echo " \033[1;31m[ OK ] | Pipex fclean ready!\033[0m"

re:			fclean all

.PHONY =	all clean fclean re
.SILENT: $(OBJS)