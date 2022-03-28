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