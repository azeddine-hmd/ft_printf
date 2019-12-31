NAME = libftprintf.a

LIBFTOB = libft/*.o

GCC = gcc -Wall -Wextra -Werror

MAKE = make -C libft

MCF =	ft_printf.c \
		ft_linkedlist.c \
		ft_insert_data.c \
		ft_insert_data_utils.c \
		ft_manipulate_data.c \
		ft_lstprint_string.c \
		ft_flags_handler.c \
		ft_c_handler.c \
		ft_s_handler.c \
		ft_s_handler_utils.c \
		ft_d_handler.c \
		ft_d_handler_utils.c \
		ft_i_handler.c \
		ft_u_handler.c \
		ft_u_handler_utils.c \
		ft_x_handler.c \
		ft_x_handler_utils.c \
		ft_capital_x_handler.c \
		ft_capital_x_handler_utils.c \
		ft_p_handler.c \
		ft_p_handler_utils.c \
		ft_percentage_handler.c \

MOF = ${MCF:.c=.o}

ARCHIVE = ar rc

RM = rm -f

all: $(NAME)

$(NAME):
	$(MAKE) all
	$(GCC) -c $(MCF)
	$(ARCHIVE) $(NAME) $(MOF) $(LIBFTOB)

clean:
	$(MAKE) clean
	$(RM) $(MOF)

fclean: clean
	$(MAKE) fclean
	$(RM) $(NAME)
	$(RM)r a.out*

re: fclean all
