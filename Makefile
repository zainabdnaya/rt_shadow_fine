# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 19:39:54 by zdnaya            #+#    #+#              #
#    Updated: 2020/11/06 22:33:51 by zdnaya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=  miniRT

MLX 		    = -lmlx -lm -framework OpenGL -framework AppKit


CFLAGE =  -Wall -Wextra -Werror

SRCS			=  work/main.c\
				   work/error.c\
				   work/first_parsing.c\
				   work/camera.c\
				   work/parsing_RT.c\
				   work/color.c\
				   work/raytracing.c\
				   work/mlx_configue.c\
				   work/vector_1.c\
				   work/vector_2.c\
				   work/vector_3.c\
				   work/image.c\
				   work/check.c\
				   work/phong.c\
				   work/list.c\
				   work/list1.c\
				   work/print_list.c\
				   work/shading.c\
				   work/plan.c\
				   work/sphere.c\
				   work/triangle.c\
				   work/cylindre.c\
				   work/square.c\
				   tools/get_next_line.c\
				   tools/get_next_line_utils.c\
				   tools/ft_compare_end.c\
				   tools/ft_charSplit.c\
				   tools/ft_count.c\
				   tools/ft_samestr.c\
				   tools/ft_stringdel.c\
				   tools/ft_free_split.c\
				   tools/ft_calloc.c\
				   tools/ft_charCount.c\
				   tools/ft_lstsize.c\
				   tools/ft_list.c\
				   tools/add_list_back.c\
				   tools/convert_to_double.c\
				   tools/my_power.c\
				   tools/ft_atoi.c\
				   tools/ft_split.c\
				   tools/ft_isdigit.c\
				   tools/ft_strdup.c\
				   tools/ft_strlen.c\

				   
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
				@rm -rf miniRT
				@gcc $(OBJ) -I./includes -I./usr/include $(CFLAGE) $(MLX) -o $(NAME)
				@echo "   Made by : \033[1;91mzdnaya\033[m"
				@echo "          _       _______ _____    "
				@echo "         (_)     (_) ___ \_   _|   "
				@echo "  _ __ ___  _ _ __  _| |_/ / | |   "
				@echo " | '_ ' _ \| | '_ \| |    /  | |   "
				@echo " | | | | | | | | | | | |\ \  | |   "
				@echo " |_| |_| |_|_|_| |_|_\_| \_| \_/   "
				@echo "Compilation of miniRT:  \033[1;91mDONE\033[m"


clean:
		@rm -rf $(OBJ)
		@echo "miniRT : Removing Objs"

fclean: clean
		@rm -rf $(NAME)
		@echo "miniRT : Removing miniRT"

re: fclean all