NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

MAKE = cd libft && make

MCF = ft_printf.c

MO = ft_printf.o

ARCHIVE = ar rc

RM = rm -f

all: $(NAME)

$(NAME):
	$(MAKE) all
	$(CC) $(CF)
	$(ARCHIVE) $(NAME) $(MO)

clean:
	$(MAKE) clean
	$(RM) $(O)

fclean: clean
	$(MAKE) fclean
	$(RM) $(NAME)

re: fclean all
