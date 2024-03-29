# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/23 15:39:57 by sofiahechai       #+#    #+#              #
#    Updated: 2020/10/25 19:38:10 by sofiahechai      ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 	=	cub3d

HEADER 	=	./includes/cub3d.h

MINILIB = 	./minilibx/ -framework OpenGL -framework AppKit

SRC 	=	./srcs/main.c\
			./srcs/ft_openwindow.c\
			./srcs/ft_savefile.c\
			./srcs/ft_saveres.c\
			./srcs/ft_atoiwithst.c\
			./srcs/ft_savecolor.c\
			./srcs/ft_savetexture.c\
			./srcs/ft_jumpspaces.c\
			./srcs/ft_searchtexture.c\
			./srcs/ft_errormsg.c\
			./srcs/ft_savespritetexture.c\
			./srcs/ft_gotomap.c\
			./srcs/ft_checkdouble.c\
			./srcs/ft_checkmaperror.c\
			./srcs/ft_putxonmap.c\
			./srcs/ft_errormsgcandf.c\
			./srcs/ft_checkmapcar.c\
			./srcs/ft_settextures.c\
			./srcs/ft_playermouv.c\
			./srcs/ft_playerrotation.c\
			./srcs/raycasting/ft_cub3d.c\
			./srcs/raycasting/ft_calcultexture.c\
			./srcs/raycasting/ft_putpixel.c\
			./srcs/raycasting/ft_calculsprite.c\
			./srcs/raycasting/ft_drawsprite.c\
			./srcs/raycasting/ft_setdrawsprite.c\
			./srcs/raycasting/ft_raycasting.c\
			./srcs/utils/ft_free.c\
			./srcs/utils/ft_exit.c\
			./srcs/utils/ft_initstruct.c\
			./srcs/utils/ft_initstruct2.c\
			./srcs/utils/ft_saveimage.c\

FLAGS 	=	-Wall -Wextra -Werror

OBJ		= 	$(SRC:.c=.o)

RM		=	rm -rf

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@make  -C libft
	 		@gcc $(FLAGS) -I includes -o $@ $^ minilibx/libmlx.a libft/libft.a -I $(HEADER) -L $(MINILIB)
	@echo "\n\033[1;32m╔═══════════════════════════════════════════╗\033[0m"
	@echo "\033[1;32m║ ███████╗██╗   ██╗██████╗ ██████╗ ██████╗  ║\033[0m"
	@echo "\033[1;32m║ ██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗ ║\033[0m"
	@echo "\033[1;32m║ ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║ ║\033[0m"
	@echo "\033[1;32m║ ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║ ║\033[0m"
	@echo "\033[1;32m║ ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝ ║\033[0m"
	@echo "\033[1;32m║ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝   ║\033[0m"
	@echo "\033[1;32m╚═══════════════════════════════════════════╝\033[0m"
	@echo "\033[1;32m\n\nTo start the game, please run: ./cub3d <map_file>.cub\n\033[0m"


%.o: %.c 	@includes/cub3d.h
	 		@gcc -I includes -o $@ -c $< $(FLAGS)
			

clean:
			@$(MAKE) clean -C libft
			@$(RM) $(OBJ)
	@echo "\n\033[1;32m╔═══════════════════════════════════════════╗\033[0m"
	@echo "\033[1;32m║ ███████╗██╗   ██╗██████╗ ██████╗ ██████╗  ║\033[0m"
	@echo "\033[1;32m║ ██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗ ║\033[0m"
	@echo "\033[1;32m║ ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║ ║\033[0m"
	@echo "\033[1;32m║ ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║ ║\033[0m"
	@echo "\033[1;32m║ ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝ ║\033[0m"
	@echo "\033[1;32m║ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝   ║\033[0m"
	@echo "\033[1;32m╚═══════════════════════════════════════════╝\033[0m"
	@echo "\033[1;32m\n\nEvrythings clean, thank you :)\n\033[0m"

fclean: 	clean
			@$(RM) $(NAME)
			@$(RM) libft/*.a

re: 		fclean all

.PHONY: 	re fclean clean all
