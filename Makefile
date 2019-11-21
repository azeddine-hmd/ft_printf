NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

MAKE = make -C libft

MCF = ft_printf.c

MOF = ft_printf.o

ARCHIVE = ar rc

RM = rm -f

all: $(NAME)

$(NAME):
	$(MAKE) all
	$(CC) -c $(MCF)
	$(ARCHIVE) $(NAME) $(MOF)

clean:
	$(MAKE) clean
	$(RM) $(MOF)

fclean: clean
	$(MAKE) fclean
	$(RM) $(NAME)

re: fclean all
