# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/10 19:48:33 by pcamaren          #+#    #+#              #
#    Updated: 2021/10/06 17:15:41 by pcamaren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
LFLAGS	= -L $(LIBFT) -L $(MLX)
LINKS	= -lmlx -lm -lX11 -lXext -lm -lft -lz

### EXECUTABLE ###
NAME	= fractol

### INCLUDES ###
LIBFT	= libft
OBJ_DIR	= bin
HEADER	= includes
SRC_DIR	= src
MLX		= minilibx-linux

### SOURCE FILES ###
SRCS	= fractol.c \

### OBJECTS ###
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

### COLORS ###
NOC		= \033[0m
BLACK	= \033[1;30m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
PURPLE	= \033[1;35m
CYAN	= \033[1;36m
WHITE	= \033[1;37m

### RULES ###
all:	$(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(NOC)"
	@make -C $(LIBFT)
	@make -C $(MLX)

$(NAME):	lib $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(LFLAGS) $(LINKS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Project successfully compiled$(NOC)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(CFLAGS) -I$(HEADER) -I$(LIBFT) -I$(MLX) -c $< -o $@
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(GREEN)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Supressing libraries files$(NOC)"
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@echo "$(GREEN)Supressing object files$(NOC)"
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@make fclean -C $(LIBFT)
	@echo "$(GREEN)Supressing program file$(NOC)"
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re