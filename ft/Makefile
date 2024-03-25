# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/04 18:44:30 by smatsuo           #+#    #+#              #
#    Updated: 2023/09/05 23:19:44 by smatsuo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC 			= cc
CFLAGS		= -Wall -Werror -Wextra
SRCS		= $(shell find ctype string stdlib stdio -type f -name '*.c')
OBJS		= $(SRCS:.c=.o)
INCLUDE		= -I.
TESTS_DIR	= .tester

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $^
	
.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

setup:
	$(RM) compile_commands.json
	compiledb make

setup-test:
	mkdir -p $(TESTS_DIR)
	cd $(TESTS_DIR); git clone git@github.com:TR-42/libftTester-forReloaded.git; git clone git@github.com:usatie/libft-tester-tokyo.git; git clone git@github.com:alelievr/libft-unit-test.git

test: all
	make -C $(TESTS_DIR)/libftTester-forReloaded a LIBFT_PATH=$(shell pwd)
	make -C $(TESTS_DIR)/libft-tester-tokyo all LIBFT_DIR=$(shell pwd)
	make -C $(TESTS_DIR)/libft-unit-test LIBFTDIR=$(shell pwd)

.PHONY: all clean fclean re
