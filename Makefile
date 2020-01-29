# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/02 07:12:48 by ishaimou          #+#    #+#              #
#    Updated: 2019/07/31 06:35:34 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BGREEN = \033[1;32m
BCYAN = \033[1;36m
RESET = \033[0m
BEER = 🍻
BOOKS = 📚i
CLEAN = ✅
FCLEAN = 😥

NAME = lem-in
LIB_NAME = libft.a
LIB_DIR = ./libft
LIB = -L ./libft -lft
H_LIB_DIR = ./libft/includes
H_DIR = ./includes
FLAGS = -Wall -Werror -Wextra

CC = gcc

SRCS = 	main.c init.c tools.c tools2.c special_tools.c free.c manager_tools.c manager.c\
		best_group.c links_rooms.c parse.c algo_ishobe.c fill_grp_infos.c\
		ultimate.c bfs.c calcul_ants_shots.c exclus_edgeflow.c find_squad.c\

SRCS_DIR = $(addprefix srcs/, $(SRCS))

SRCS_O = $(SRCS_DIR: %.c=%.o)

all: $(NAME)

$(NAME): $(SRCS_O)
	@make -C $(LIB_DIR)
	@echo "$(BOOKS) $(BGREEN)$(LIB_NAME) has been created successfully.$(RESET)"
	@$(CC) -o $(NAME) $(SRCS_O) -I $(H_DIR) -I $(H_LIB_DIR) $(LIB) $(FLAGS)
	@echo "$(BEER)  $(BGREEN)$(NAME) has been created successfully.$(RESET)"
	@echo ""
	@echo ""
	@echo "$(BGREEN)"
	@echo "              ,"
	@echo '     _,-`\   /|   .    .    /`.'
	@echo ' _,-`     \_/_|_  |\   |`. /   `._,--===--.__'
	@echo '        _/"/  " \ : \__|_ /.   ,"    :.  :. .`-._'
	@echo '       // ^   /7 t`""    "`-._/ ,"\   :   :  :  .`.'
	@echo '       Y      L/ )\         ]],`   \  :   :  :   : `.'
	@echo '       |        /  `.n_n_n,","\_    \ ;   ;  ;   ;  _>'
	@echo '       |__    ,`     |  \`-`    `-.__\_______.==---"'
	@echo '      //  `""\\      |   \            \'
	@echo '      \|     |/      /    \            \'
	@echo '                    /     |             `.'
	@echo '                   /      |               ^'
	@echo '                  ^       |'
	@echo "                          ^   $(BCYAN) ISHOBE$(RESET) Take care of ants"
	@echo "$(RESET)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@make clean -C $(LIB_DIR)
	@echo "$(CLEAN)  $(BCYAN)Object files has been cleaned successfully.$(RESET)"

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -rf $(NAME)
	@echo "$(FCLEAN)  $(BCYAN)$(NAME) cleaned successfully.$(RESET)"

re: fclean all
