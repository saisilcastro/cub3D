ifneq ($(OS), Windows_NT)
	NAME = cub3D
	CREATE = mkdir -p $(1)
	REMOVE = rm -rf $(1)
endif
VPATH = src: ./src/common src: ./src/mandatory src: ./src/plugin
INCLUDE = -I./include \
		  -I./MLX42/include
SRC_COMMON = 	chained.c \
				math-of.c \
				image.c \
				image-next.c \
				object.c \
				machine.c \
				cub3d-run.c \
				cub3d-mouse.c \
				cub3d.c
SRC_PLUGIN =	mlx-plugin.c \
				mlx-plugin-mouse.c \
				mlx-plugin-rect.c \
				mlx-ray-cast.c
SRC_MANDATORY = user-init.c \
				user-update.c \
				user-draw.c
SRC =	$(SRC_COMMON) \
		$(SRC_PLUGIN) \
		$(SRC_MANDATORY) \
		main.c
OBJ = obj
SRCOBJ = $(SRC:%.c=${OBJ}/%.o)
LIB = -L./MLX42/build
FLAG = -lmlx42 -ldl -lglfw -pthread -lm

all: $(NAME)
$(NAME): $(SRCOBJ)
	$(CC) $^ $(LIB) $(FLAG) -o $(NAME)
${OBJ}/%.o : %.c
	$(call CREATE,${OBJ})
	$(CC) -c $< -o $@ $(INCLUDE)
clean:
	$(call REMOVE,${OBJ})
fclean: clean
	$(call REMOVE, ${NAME})
re: fclean all
play:
	./$(NAME)
leak:
	valgrind --leak-check=full -q ./$(NAME)