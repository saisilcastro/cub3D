ifneq ($(OS), Windows_NT)
	CREATE = mkdir -p $(1)
	REMOVE = rm -rf $(1)
endif
CUB = cub3D
VPATH = src: ./src/common src: ./src/plugin src: ./src/mandatory
SRC_COMMON =	file-of.c \
				level.c \
				machine.c \
				math-of.c \
				angle.c \
				primitive-of.c \
				image-of.c \
				object.c \
				object-angle.c \
				cub3D.c \
				cub3D-run.c
SRC_PLUGIN =	mlx-plugin.c \
				mlx-plugin-mouse.c \
				mlx-plugin-line.c \
				mlx-plugin-rect.c \
				mlx-ray-cast.c
SRC_MANDATORY = user-init.c \
				user-draw.c \
				user-update.c
SRC = 	$(SRC_COMMON) \
		$(SRC_PLUGIN) \
		$(SRC_MANDATORY) \
		main.c
INCLUDE = -I./include \
		  -I./MLX42/include
OBJ = obj
SRCOBJ = $(SRC: %.c=${OBJ}/%.o)
LIB = -L./MLX42/build
FLAG = -lmlx42 -ldl -lglfw -pthread -lm

all: $(CUB)
$(CUB): $(SRCOBJ)
	$(CC) $^ $(INCLUDE) $(LIB) $(FLAG) -o $(CUB)
${OBJ}/%.o : %.c
	$(call CREATE,${OBJ})
	$(CC) -c $< -o $@
clean:
	$(call REMOVE,${OBJ})
fclean: clean
	$(call REMOVE,${CUB})
re: fclean all
leak:
	valgrind --leak-check=full -q ./$(CUB)