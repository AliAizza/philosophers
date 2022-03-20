# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 11:52:07 by aaizza            #+#    #+#              #
#    Updated: 2022/03/20 11:55:01 by aaizza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

FLAGS = -Wall -Wextra -Werror

SRCS = actions.c philosophers.c utils.c

all : $(NAME)

$(NAME) : $(SRCS)
	@gcc $(FLAGS) $(SRCS) -o $(NAME)
	@echo "✅"

clean :
	@rm -f $(NAME)
	@echo "🗑️"

fclean : clean

re : fclean all