# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/23 15:39:57 by sofiahechai       #+#    #+#              #
#    Updated: 2020/10/13 15:38:39 by sofiahechai      ###   ########lyon.fr    #
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
			./srcs/utils/ft_free.c\
			./srcs/utils/ft_initstruct.c\

FLAGS 	=	-Wall -Wextra -Werror

OBJ		= 	$(SRC:.c=.o)

RM		=	rm -rf

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@make  -C minilibx
			@make  -C libft
	 		@gcc $(FLAGS) -I includes -o $@ $^ minilibx/libmlx.a libft/libft.a -I $(HEADER) -L $(MINILIB)
	@echo " \033[2K\r\033[95m\n\n\n\n\n\n.\n.\n..\n...\n....\n....\n...\n..\n.\n.\033[0m"
	@echo " \033[2K\r\033[95m.\n.\n..\n...\n....\n....\n...\n..\n.\n.\033[0m"
	@echo "	\033[2K\r\033[95m\n$(NAME) is ready to be executed :)\n\033[0m"
	@echo "	\033[2K\r\033[95m\nTo start the game please type : ./cub3d and add a map file ending by '.cub' :\n\033[0m"


%.o: %.c 	@includes/cub3d.h
	 		@gcc -I includes -o $@ -c $< $(FLAGS)

clean:
			@$(MAKE) clean -C minilibx
			@$(MAKE) clean -C libft
			@$(RM) $(OBJ)
	@echo " \033[2K\r\033[0;38;5;121m\n\n\n\n\n\n.\n.\n..\n...\n....\n....\n...\n..\n.\n.\033[0m"
	@echo " \033[2K\r\033[0;38;5;121m.\n.\n..\n...\n....\n....\n...\n..\n.\n.\033[0m"
	@echo "\033[2K\033[0;38;5;121m\n./$(NAME), *.o and *.a have been deleted\n\nFiles of $(NAME) are now clean :)\n"

fclean: 	clean
			@$(RM) $(NAME)
			@$(RM) libft/*.a
			@$(RM) minilibx/*.a

re: 		fclean all

.PHONY: 	re fclean clean all