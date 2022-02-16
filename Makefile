# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 08:15:27 by dvan-der          #+#    #+#              #
#    Updated: 2021/12/15 08:15:28 by dvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME := push_swap

SRCS := \
main.c \
input.c \
stack.c \
letsgo.c \
executions.c \
sort_small_stack.c \
sort_big_stack.c

OBJS := ${SRCS:%.c=%.o}

LIBFT := libft/libft.a
HEADERFILES := push_swap.h
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $@ $^

$(LIBFT):
	$(MAKE) bonus -C libft

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME) $^

re:	fclean all

.PHONY: all, clean, fclean, re