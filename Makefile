ifneq ($(OS), Windows_NT)
	NAME = cub3D
	CREATE = @mkdir -p $(1)
	REMOVE = @rm -rf $(1)
endif
VPATH = src: ./src/common src: ./src/mandatory src: ./src/plugin
INCLUDE = -I./include \
		  -I./MLX42/include \
		  -I./libft
SRC_COMMON = 	chained.c \
				angle.c \
				math-of.c \
				pixel.c \
				image.c \
				image-next.c \
				image-util.c \
				object.c \
				object-next.c \
				object-angle.c \
				machine.c \
				cub3d-run.c \
				cub3d-mouse.c \
				cub3d.c
SRC_PLUGIN =	mlx-plugin.c \
				mlx-plugin-line.c \
				mlx-plugin-mouse.c \
				mlx-plugin-rect.c \
				mlx-texture-draw.c \
				mlx-ray-cast.c
SRC_MANDATORY = check-map.c \
				map-draw.c \
				user-init.c \
				user-update.c \
				user-draw.c
SRC =	$(SRC_COMMON) \
		$(SRC_PLUGIN) \
		$(SRC_MANDATORY) \
		main.c
OBJ = obj
SRCOBJ = $(SRC:%.c=${OBJ}/%.o)
LIB = -L./MLX42/build \
	  -L./libft
FLAG = -lmlx42 -ldl -lglfw -pthread -lm -lft
PURPLE = \033[1;35m

all: $(NAME)
$(NAME): $(SRCOBJ)
	@$(MAKE) -C ./libft --silent
	@printf "\nThe Makefile of [$(PURPLE)Cub3D\033[0m] has been compiled!🐚\n"
	@$(CC) $^ $(LIB) $(FLAG) -o $(NAME)
${OBJ}/%.o : %.c
	@$(call CREATE,${OBJ})
	@printf "\rCub3D: building $@                      "
	@$(CC) -c $< -o $@ $(INCLUDE)
clean:
	$(call REMOVE,${OBJ})
	$(call REMOVE,./libft/*.o)
fclean: clean
	$(call REMOVE,${NAME})
	$(call REMOVE,./libft/libft.a)
re: fclean all
play:
	./$(NAME) map.cub
leak:
	valgrind --leak-check=full -q ./$(NAME) minimalist.cub
fucker:
	valgrind --leak-check=full -q ./$(NAME) map.cub