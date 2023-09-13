# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 17:51:43 by mrabat            #+#    #+#              #
#    Updated: 2023/09/07 09:49:43 by mrabat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m

NAME = fdf
MINILIBX = minilibx

# Dossiers
SRCDIR = sources
OBJDIR = obj
INCLUDEDIR = includes
LIBFTDIR = includes/libft
LIBMINIDIR_MACOS = includes/${MINILIBX}_macos
LIBMINIDIR_ORIGIN = includes/${MINILIBX}_linux

# Compilateur et options
CC = gcc
CFLAGS = -g
# -Wall -Werror -Wextra -g

MACFLY =  -lXext -lX11 -lm -lbsd 
# Dectection du system 
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	MACFLY = -framework OpenGL -framework AppKit
	LIBMINIDIR_ORIGIN = $(LIBMINIDIR_MACOS)
endif

# Noms des fichiers
LIBFT = $(LIBFTDIR)/libft.a
LIBMINI = $(INCLUDEDIR)/libmlx.a

# Fichiers sources et objets
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Règle par défaut
all: $(NAME)

# Création du dossier obj s'il n'existe pas
$(shell mkdir -p $(OBJDIR))

# Règle de construction de l'exécutable
$(NAME): $(LIBFT) $(LIBMINI) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMINI) $(MACFLY) -o $(NAME)
	@echo "$(BLUE)$(NAME) READY IN BIN FOLDER$(DEF_COLOR)"

# Règle de compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)OBJ CREDD$(DEF_COLOR)"

# Règle de construction de la bibliothèque libft.a
$(LIBFT):
	$(MAKE) -sC $(LIBFTDIR) all
	@echo "$(YELLOW)LIBFT COMPILED$(DEF_COLOR)"

$(LIBMINI):
	$(MAKE) -Cs $(LIBMINIDIR_ORIGIN)
	$(shell yes | cp -r $(LIBMINIDIR_ORIGIN)/mlx.h $(INCLUDEDIR)/mlx.h)
	$(shell yes | cp -r $(LIBMINIDIR_ORIGIN)/libmlx.a  $(INCLUDEDIR)/libmlx.a)
	@echo "$(GREEN)LIBMINI COMPILED$(DEF_COLOR)"

# Règle de nettoyage des fichiers objets
clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm $(INCLUDEDIR)/libmlx.a
	rm -rf $(OBJDIR)
	@echo "$(BLUE)cleaned!$(DEF_COLOR)"

# Règle de nettoyage complet
fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm $(NAME)
	@echo "$(RED)cleaned!$(DEF_COLOR)"

# Règle de recompilation complète
re: fclean all

.PHONY: all clean fclean re

