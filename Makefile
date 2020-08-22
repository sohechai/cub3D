# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/23 15:39:57 by sofiahechai       #+#    #+#              #
#    Updated: 2020/08/22 18:46:48 by sohechai         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 	=	cub3d

HEADER 	=	./includes

MINILIB = 	./minilibx/ -framework OpenGL -framework AppKit

SRC 	=	./srcs/main.c\
			./srcs/ft_openwindow.c\
			./srcs/ft_cub3d.c\
			./srcs/ft_color.c\
			./srcs/ft_check.c\
			./srcs/ft_savefile.c\

FLAGS 	=	-Wall -Wextra -Werror

OBJ		= 	$(SRC:.c=.o)

RM		=	rm -rf

BLUE =\033[0;38;5;123m
LIGHT_PINK = \033[95m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[0;38;5;121m
LIGHT_RED = \033[0;31;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m
GREY = \033[3;90m
ORANGE = \033[3;91m
YELLOW = \033[0;33m

all: 		$(NAME)
	@:

$(NAME): 	$(OBJ)
	 		@$(MAKE)  -C minilibx
			@$(MAKE)  -C libft
	 		@gcc -I includes -o $@ $^ minilibx/libmlx.a libft/*.a $(FLAGS) -I $(HEADER) -L $(MINILIB)
	@echo " \033[2K\r$(LIGHT_PINK)\n\n\n\n\n\n.\n.\n..\n...\n....\n....\n...\n..\n.\n.\033[0m"
	@echo " \033[2K\r$(LIGHT_PINK).\n.\n..\n...\n....\n....\n...\n..\n.\n.\033[0m"
	@echo "	\033[2K\r$(LIGHT_PINK)\n$(NAME) is ready to be executed :)\n\033[0m"
	@echo "	\033[2K\r$(LIGHT_PINK)\nTo start the game please type : ./cub3d and add a map file ending by '.cub' :\n\033[0m"

%.o: %.c 	@includes/cub3d.h
	 		@gcc -I includes -o $@ -c $< $(FLAGS)

clean:
			@$(MAKE) clean -C minilibx
			@$(MAKE) clean -C libft
			@$(RM) $(OBJ)
			@echo " \033[2K\r$(LIGHT_GREEN)\n\n\n\n\n\n.\n.\n..\n...\n....\n....\n...\n..\n.\n.\033[0m"
			@echo " \033[2K\r$(LIGHT_GREEN).\n.\n..\n...\n....\n....\n...\n..\n.\n.\033[0m"
			@echo "\033[2K$(LIGHT_GREEN)\n./$(NAME), *.o and *.a have been deleted\n\nFiles of $(NAME) are now clean :)\n"

fclean: 	clean
			@$(RM) $(NAME)
			@$(RM) libft/*.a
			@$(RM) minilibx/*.a

re: 		fclean all

.PHONY: 	re fclean clean all