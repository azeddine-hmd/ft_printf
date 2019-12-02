NAME = libftprintf.a

GCC = gcc -Wall -Wextra -Werror

MAKE = make -C libft

MCF = ft_capital_x_handler.c ft_c_handler.c ft_d_handler.c ft_flags_handler.c \
	  ft_i_handler.c ft_insert_data.c ft_insert_data_utils.c ft_linkedlist.c \
	  ft_manipulate_data.c ft_percentage_handler.c ft_p_handler.c ft_printf.c \
	  ft_s_handler.c ft_u_handler.c ft_x_handler.c

MOF = ft_capital_x_handler.o ft_c_handler.o ft_d_handler.o ft_flags_handler.o \
	  ft_i_handler.o ft_insert_data.o ft_insert_data_utils.o ft_linkedlist.o \
	  ft_manipulate_data.o ft_percentage_handler.o ft_p_handler.o ft_printf.o \
	  ft_s_handler.o ft_u_handler.o ft_x_handler.o

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
