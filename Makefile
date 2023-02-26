# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 16:03:12 by tatashir          #+#    #+#              #
#    Updated: 2023/02/26 15:30:10 by tatashir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.c

OBJCS = $(SRCS:.c=.o)

PRINTFDIR = ./lib/ft_printf
GNLDIR = ./lib/get_next_line
FT_PRINTF = -L$(PRINTFDIR) -l ft_printf
GNL = -L$(GNLDIR) -l get_next_line

MLX = -lmlx - framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJCS)
	