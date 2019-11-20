NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

MCF = ft_printf.c

MOF = ft_printf.o

ARCHIVE = ar rc

RM = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(MCF)
	$(ARCHIVE) $(NAME) $(MOF)

clean:
	$(RM) $(MOF)

fclean: clean
	$(RM) $(NAME)

re: fclean all
