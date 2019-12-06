# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 16:33:34 by mpouzol           #+#    #+#              #
#    Updated: 2019/12/06 11:13:08 by mpouzol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MN = mini

OPT = -lm -lmlx -framework OpenGL -framework AppKit

SRCS =	SRCS/area_vision.c\
        SRCS/cross.c\
		SRCS/error.c\
		SRCS/get_next_line_utils.c\
		SRCS/minimap.c\
	 	SRCS/parsing.c\
		SRCS/parsing_3.c\
		SRCS/player.c\
		SRCS/rc_set.c\
		SRCS/sprite.c\
		SRCS/utils_2.c\
		SRCS/bmp.c\
		SRCS/draw.c\
		SRCS/get_next_line.c\
		SRCS/main.c\
	    SRCS/move.c\
		SRCS/parsing_2.c\
	    SRCS/parsing_4.c\
		SRCS/rc.c\
		SRCS/save.c\
		SRCS/utils.c\
		SRCS/texture.c\
		SRCS/parse_arg.c\

OBJECTS = $(SRCS:.c=.o)

HEADER = includes

FLAGS = -Wall -Wextra -Werror

CC = gcc

all : $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	$(CC) $(FLAGS) $(OPT) $(SRCS) -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean all fclean re
