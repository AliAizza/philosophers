# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaizza <aaizza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 23:38:28 by aaizza            #+#    #+#              #
#    Updated: 2022/03/28 23:38:30 by aaizza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

FLAGS = -Wall -Wextra -Werror

SRCS = init.c philosophers_bonus.c actions.c utils.c

all : $(NAME)

$(NAME) : $(SRCS)
	@gcc $(FLAGS) $(SRCS) -o $(NAME)
	@echo "✅"

clean :
	@rm -f $(NAME)
	@echo "🗑️"

fclean : clean

re : fclean all