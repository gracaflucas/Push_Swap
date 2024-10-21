# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/21 19:51:55 by lufiguei          #+#    #+#              #
#    Updated: 2024/08/21 19:51:56 by lufiguei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap
BONUS = checker

LIBFT = libft/libft.a

CC = cc
RM = rm -rf

SRC = main.c\
	error.c\
	rotate.c\
	rrotate.c\
	swaps.c\
	pushs.c\
	algorithm.c\
	stack_utils.c\
	refresh_a.c\
	refresh_b.c\
	smallsort.c\

OBJ = $(SRC:.c=.o)

BONUS_SRC = checker.c\
		get_next_line.c\
		error.c\
		rotate.c\
		rrotate.c\
		swaps.c\
		pushs.c\
		stack_utils.c\
		refresh_a.c\
		refresh_b.c\
		smallsort.c\
		algorithm.c\

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(LIBFT) $(BONUS)

$(BONUS): $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS) $(LIBFT)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)
	
fclean: clean
	$(RM) $(NAME) $(BONUS)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
