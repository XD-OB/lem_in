# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/14 20:33:38 by obelouch          #+#    #+#              #
#    Updated: 2019/07/24 20:55:42 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[1;32m
RED = \033[1;31m
EOC = \033[1;0m

LIBS_H = -I ./Library/includes/
LIBS_A = -L ./Library/lib/ -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lft\

NAME = libsdl.a

LIBSDL = sdl_bcircle sdl_bquad sdl_brect_e sdl_fsquare_a sdl_fsquare_c\
		 sdl_bline sdl_circle sdl_disk sdl_disk sdl_line sdl_quad\
		 sdl_rect_a sdl_rect_c sdl_rect_e sdl_square_a sdl_square_c\
		 sdl_init sdl_close sdl_color sdl_rgb sdlenv_init sdlenv_fill\
		 rect_new bline_new bcircle_new ttf_texture img_texture load_music\

SRC = $(addprefix srcs/, $(addsuffix .c, $(LIBSDL)))

OBJ = $(addsuffix .o, $(LIBSDL))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@make -C ./Library/libft
		@gcc -c $(SRC) $(FLAGS) -I.
		@ar rc $(NAME) $(OBJ)
		@echo "$(GREEN)"
	  	@echo "   _     _ _             _ _  "
		@echo "  | |   |_| |           | | | "
		@echo "  | |    _| |__  ___  __| | | "
		@echo "  | |   | |  _ \/ __|/ _  | | "
		@echo "  | |___| | |_| \__ \ |_| | | "
		@echo "  \_____/_|_.__/|___/\__,_|_| $(EOC)"
		@echo "by:$(RED) obelouch $(EOC) 2019"

clean:
		@make clean -C ./Library/libft
		@/bin/rm -f $(OBJ)
		@echo "$(GREEN)Clean libsdl$(EOC)"

fclean: clean
		@make fclean -C ./Library/libft
		@/bin/rm -f $(NAME)
		@echo "$(RED)Remove libsdl.a :/$(EOC)"

re: fclean all
