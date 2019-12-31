#!/bin/bash

# compiling and executing
make re && clear; gcc -Wall -Wextra -Werror -g *.c */*.c
clear; valgrind --xtree-memory=full ./a.out
make -s fclean
