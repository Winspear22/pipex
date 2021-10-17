# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 16:07:41 by adaloui           #+#    #+#              #
#    Updated: 2021/10/17 15:26:38 by adaloui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_OS = $(shell uname)

ifeq ($(NAME_OS), Darwin)
	SRC = srcs/main.c srcs/ft_check_and_init_fd.c  srcs/ft_search_command.c  srcs/ft_execute_command.c   srcs/ft_get_paths.c 
	NAME_OS = MAC
endif
ifeq ($(NAME_OS), Linux)
	SRC = srcs/main.c srcs/ft_check_and_init_fd.c  srcs/ft_search_command.c srcs/ft_execute_command.c  srcs/ft_get_paths.c \
	libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strjoin.c libft/ft_split.c \
	libft/ft_strlcpy.c libft/ft_strnstr.c libft/ft_strlen.c

endif

OBJ = *.o

FLAGS = -Wall -Wextra -Werror

LIBFT_A = libft.a
LIBFT_DOSSIER = libft/
LIBFT  = $(addprefix $(LIBFT_DOSSIER), $(LIBFT_A))

WHITE='\033[0m'
BLUE='\033[36m'
CYAN='\033[1;32m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CYAN) "Compilation en cours de $(NAME) sur l'OS \"$(NAME_OS)\"" $(WHITE)
	@make -C $(LIBFT_DOSSIER)
	@gcc $(FLAGS) $(LIBFT) $(OBJ) -o $(NAME)
	@echo ""
	@echo $(BLUE)"Tout a été compilé avec succès ! -"$(WHITE)

$(OBJ): $(SRC)
	@echo $(CYAN) "Creation des fichiers .o." $(WHITE)
	@gcc $(FALGS) -c $(SRC)

clean:
	@echo "Suppression en cours des fichiers .o de pipex et de la libft"
	@echo $(CYAN) "Suppression des fichiers .o de pipex." $(WHITE)
	@echo $(CYAN) "Suppression des fichiers .o de la libft." $(WHITE)
	@rm -f $(OBJ)
	@make -C $(LIBFT_DOSSIER) clean
	@echo "Nettoyage des fichiers .o effectué"

fclean: clean
	@echo $(CYAN) "Suppression du logiciel $(NAME)." $(WHITE)
	@rm -rf $(NAME)
	@make -C $(LIBFT_DOSSIER) fclean
	@echo "Tout a été supprimé !"

re: fclean all