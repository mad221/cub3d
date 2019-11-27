# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 16:33:34 by mpouzol           #+#    #+#              #
#    Updated: 2019/11/27 17:48:12 by mpouzol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MN = mini

OPT = -lm -lmlx -framework OpenGL -framework AppKit

SRCS =	area_vision.c\
		get_next_line.c\
		minimap.c\
		parsing_2.c\
		player.c\
		sprite.c\
		draw.c\
		get_next_line_utils.c\
		move.c\
		parsing_3.c\
		rc.c\
		utils.c\
		error.c\
		main.c\
		parsing.c\
		parsing_4.c\
		rc_set.c\
		utils_2.c\
		save.c\
		bmp.c\

OBJECTS = $(SRCS:.c=.o)

HEADER = includes

FLAGS = -Wall -Wextra -Werror

CC = gcc

all : $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	make -C $(MN)
	$(CC) $(FLAGS) $(OPT) $(SRCS) -o $@

clean :
	rm -f $(OBJECTS)
	$(MK) clean -C $(MN)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean all fclean re
