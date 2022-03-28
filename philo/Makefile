# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 11:52:07 by aaizza            #+#    #+#              #
#    Updated: 2022/03/28 01:57:33 by aaizza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Wextra -Werror

SRCS = actions.c philosophers.c utils.c init.c

all : $(NAME)

$(NAME) : $(SRCS)
	@gcc $(FLAGS) $(SRCS) -o $(NAME)
	@echo "✅"

clean :
	@rm -f $(NAME)
	@echo "🗑️"

fclean : clean

re : fclean all