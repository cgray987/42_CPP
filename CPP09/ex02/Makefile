# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgray <cgray@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 14:55:00 by cgray             #+#    #+#              #
#    Updated: 2024/10/01 16:36:20 by cgray            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CC = c++
CFLAGS = -Wall -Werror -Wextra -g -std=c++98

SRC = main.cpp
OBJ = ${SRC:.cpp = .o}

#Colors:
GREEN		=	\e[92;5;118m
GRAY		=	\e[33;2;37m
ITALIC		=	\e[33;3m
RED			:=	\033[31m
BCYAN		:=	\033[96m
NC			:=	\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(ITALIC) $(BCYAN)[ 🖩 Compiling $(NAME)... 🖩 ]$(NC)"
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(ITALIC) $(GREEN)[ ❕$(NAME) ready❕ ]$(NC)"

clean:
	@rm -rf $(NAME)
	@echo "$(RED) [ $(NAME) Removed. ]"

fclean:
	@rm -rf $(NAME)
	@echo "$(RED) [ $(NAME) Removed. ]"

re: clean all
