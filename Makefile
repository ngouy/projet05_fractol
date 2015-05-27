#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stherman <stherman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 14:58:54 by stherman          #+#    #+#              #
#    Updated: 2014/11/11 18:07:04 by ngouy            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			= gcc
NAME		= fractol

SRC			= ./Sources/All/main.c\
			  ./Sources/All/main_aux1.c\
			  ./Sources/All/color.c\
			  ./Sources/All/common_hook.c\
			  ./Sources/All/ft_op_im1.c\
			  ./Sources/All/ft_op_im2.c\
			  ./Sources/Julia/julia_display.c\
			  ./Sources/Julia/julia_init.c\
			  ./Sources/Julia/julia_spec_hooks.c\
			  ./Sources/Mandelbrot/mandelbrot_display.c\
			  ./Sources/Mandelbrot/mandelbrot_init.c\
			  ./Sources/Mandelbrot/mandelbrot_spec_hooks.c\
			  ./Sources/Burning\ ship/burning_ship_display.c\
			  ./Sources/Burning\ ship/burning_ship_init.c\
			  ./Sources/Burning\ ship/burning_ship_spec_hooks.c\
			  ./Sources/Others/other_display.c\
			  ./Sources/Others/other_init.c\
			  ./Sources/Others/other_spec_hooks.c\

OBJ			= ./main.o\
			  ./color.o\
			  ./common_hook.o\
			  ./julia_display.o\
			  ./julia_init.o\
			  ./julia_spec_hooks.o\
			  ./mandelbrot_display.o\
			  ./mandelbrot_init.o\
			  ./mandelbrot_spec_hooks.o\
			  ./burning_ship_display.o\
			  ./burning_ship_init.o\
			  ./burning_ship_spec_hooks.o\
			  ./other_display.o\
			  ./other_init.o\
			  ./other_spec_hooks.o\
			  ./ft_op_im1.o\
			  ./ft_op_im2.o\
			  ./main_aux1.o\

CFLAGS		= -Wall -Wextra -ansi -pedantic
OFLAGS		= -O3
MAKELIBFT	= make -C ./libft/
LIBS		= ./libft/libft.a ./mlx/libmlx.a -framework OpenGl -framework AppKit

RM			= rm -rf

all: $(NAME)

$(NAME):
			$(MAKELIBFT)
			make clean -C ./mlx/
			make -C ./mlx/
			gcc $(CFLAGS) -c $(SRC) -I ./Includes/
			gcc $(OBJ) $(LIBS) -o $(NAME)
clean:
			$(RM) $(OBJ)
			$(MAKELIBFT) clean


fclean:		clean
			$(RM) $(NAME) 
			$(MAKELIBFT) fclean

re:			fclean all

norminette :
	norminette $(SRC) Include/*.h

.PHONY:		all clean re fclean
