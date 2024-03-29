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


### Compilation ###
CC      = gcc -O2 -g
FLAGS  = -Wall -Wextra -Werror

### Executable ###
NAME   = fractol

### Includes ###
LIBFT  = libft
OBJ_PATH  = objs
HEADER = includes
SRC_PATH  = sources
MLX = minilibx-linux

### Source Files ###

SOURCES =	movements.c \
			draw.c \
			fractol.c \
			init.c \
			pixel_output.c \
			parsing.c \
			zoom.c \
			free_fractol.c \

### Objects ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###

all: lib tmp $(NAME)

lib:
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)
	@make -C $(MLX)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -L $(LIBFT) -L $(MLX) -o $@ $^ -lft -lmlx -lXext -lX11 -lm
	@echo "$(GREEN)Project compiled succesfully"

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo "$(WHITE)Creation of object file -> $(BLUE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Cleaning libraries$(CYAN)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "$(GREEN)Cleaning libraries files$(CYAN)"
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: temporary, re, fclean, clean