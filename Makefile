# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 15:04:14 by lumedeir          #+#    #+#              #
#    Updated: 2024/03/07 16:42:33 by lumedeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the executable
NAME = cub3D

# Compilation flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 
BUILD = ./objs/

# Libft
INCLUDE = -I./includes
LIBFT = ./src/Libft/

SRC =	main.c \
		map_validate.c \
		check_input.c \


$(BUILD)%.o:src/%.c
		@mkdir -p $(BUILD) 
		@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

OBJ = $(addprefix $(BUILD), $(SRC:.c=.o))

PURPLE = \033[1;35m
WHITE = \033[1;37m
CYAN= \033[0;36m

all: $(NAME)

$(NAME) : $(OBJ)
		@make -C $(LIBFT) --silent
		@$(CC) $(OBJ) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME)
		@echo "$(PURPLE)The Makefile of [CUB_3D] has been compiled!🤠"

clean:
		@make clean -C $(LIBFT) --silent
		@rm -rf $(BUILD) $(BUILD_BONUS)

fclean: clean
		@echo "$(WHITE)   Cleaning all... 🧹"
		@make fclean -C $(LIBFT) --silent
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re