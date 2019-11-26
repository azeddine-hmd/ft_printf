NAME = libftprintf.a

GCC = gcc -Wall -Wextra -Werror

MAKE = make -C libft

MCF = ft_printf.c ft_data_handler.c ft_data_handler_utils.c

MOF = ft_printf.o ft_data_handler.o ft_data_handler_utils.o

ARCHIVE = ar rc

RM = rm -f

all: $(NAME)

$(NAME):
	$(MAKE) all
	$(GCC) -c $(MCF)
	$(ARCHIVE) $(NAME) $(MOF)

clean:
	$(MAKE) clean
	$(RM) $(MOF)

fclean: clean
	$(MAKE) fclean
	$(RM) $(NAME)

re: fclean all
