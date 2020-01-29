# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 23:50:43 by ishaimou          #+#    #+#              #
#    Updated: 2019/07/31 08:09:58 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BGREEN = \033[1;32m
BCYAN = \033[1;36m
RESET = \033[0m

NAME = displayer

LIB_NAME = libft.a

LIBFT_DIR = ../libft

LIBSDL_DIR = ./libsdl

LIBFT = -L ../libft -lft

LIBSDL = -L ./libsdl -lsdl

LIB_SDL2 = -L ~/.brew/Cellar/sdl2/2.0.9_1/lib/ -lSDL2

LIB_SDL2_IMG = -L ~/.brew/Cellar/sdl2_image/2.0.4/lib/ -lSDL2_image

LIB_SDL2_TTF = -L ~/.brew/Cellar/sdl2_ttf/2.0.14/lib/ -lSDL2_ttf

LIB_SDL2_MIXER = -L ~/.brew/Cellar/sdl2_mixer/2.0.4/lib -lSDL2_mixer

H_LIBFT = ../libft/includes

H_DIR = ./includes

H_LIBSDL = ./libsdl

FLAGS = -Wall -Werror -Wextra

SRCS = alloc_places.c take_cmds.c main.c tools.c color_tools.c draw_ant.c\
	   draw_rooms.c event.c free.c init.c print_debug.c print_life_ants.c\
	   fill.c fill_adv_infos.c store_data.c hash_tools.c draw_scene.c\
	   draw_state.c print_usage.c

SRCS_DIR = $(addprefix srcs/, $(SRCS))

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_DIR)
	@make -C $(LIBSDL_DIR)
	@echo "$(BGREEN) "
	@echo " ██████╗ ██████╗ ███████╗██╗███████╗██╗  ██╗"
	@echo "██╔═══██╗██╔══██╗██╔════╝██║██╔════╝██║  ██║"
	@echo "██║   ██║██████╔╝█████╗  ██║███████╗███████║"
	@echo "██║   ██║██╔══██╗██╔══╝  ██║╚════██║██╔══██║"
	@echo "╚██████╔╝██████╔╝███████╗██║███████║██║  ██║"
	@echo " ╚═════╝ ╚═════╝ ╚══════╝╚═╝╚══════╝╚═╝  ╚═╝"
	@echo " $(BCYAN)The Best tool to supervise your dirty ants!"
	@echo ""
	@echo "$(RESET)"
	@gcc -o $(NAME) $(SRCS_DIR) -I $(H_LIBFT) -I $(H_DIR) -I $(H_LIBSDL) $(LIBFT) $(LIBSDL)\
		$(LIB_SDL2) $(LIB_SDL2_IMG) $(LIB_SDL2_TTF) $(LIB_SDL2_MIXER) $(FLAGS)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBSDL_DIR)
	@echo "$(BCYAN)Object files has been cleaned successfully.$(RESET)"

fclean: clean
	@make fclean -C $(LIBSDL_DIR)
	@rm -rf $(NAME)
	@echo "$(BCYAN)$(NAME) cleaned successfully.$(RESET)"

re: fclean all
