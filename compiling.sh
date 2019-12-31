#!/bin/bash

# compiling and executing
make re && clear; gcc -Wall -Wextra -Werror -g *.c */*.c && clear; ./a.out
make -s fclean
