ifneq ($(OS), Windows_NT)
	NAME = cub3D
	CREATE = @mkdir -p $(1)
	REMOVE = @rm -rf $(1)
endif
VPATH = src: ./src/common src: ./src/mandatory ./src/bonus src: ./src/plugin
INCLUDE = -I./include \
		  -I./MLX42/include \
		  -I./libft
SRC_COMMON = 	draw.c \
				image.c \
				math.c \
				mouse.c \
				object-event.c \
				object.c \
				pixel.c \
				ray-aux.c \
				ray-cast.c \
				vector-vd2d.c \
				vector-vi2d.c
SRC_BASE =	event.c \
			game.c \
			map-utils.c \
			map-validate.c \
			map.c
SRC_EXTRA =	event-bonus.c \
			game-bonus.c \
			map-bonus-utils.c \
			map-bonus-validate.c \
			map-bonus.c \
			minimap.c
SRC_MANDATORY =	$(SRC_COMMON) \
				$(SRC_BASE) \
				main.c
SRC_BONUS =	$(SRC_COMMON) \
			$(SRC_EXTRA)\
			main.c
OBJ = obj
SRCOBJ = $(SRC_MANDATORY:%.c=${OBJ}/%.o)
SRCOBJB = $(SRC_BONUS:%.c=${OBJ}/%.o)
LIB = -L./MLX42/build \
	  -L./libft
FLAG = -lmlx42 -ldl -lglfw -pthread -fomit-frame-pointer -finline-functions -g3 -lm -lft
PURPLE = \033[1;35m

all: $(NAME)
$(NAME): $(SRCOBJ)
	@$(MAKE) -C ./libft --silent
	@printf "\nThe Makefile of [$(PURPLE)Cub3D\033[0m] has been compiled!🤠\n"
	@$(CC) $^ $(LIB) $(FLAG) -o $(NAME)
bonus: $(SRCOBJB)
	@$(MAKE) -C ./libft --silent
	@printf "\nThe Makefile of [$(PURPLE)Cub3D bonus\033[0m] has been compiled!🤠\n"
	@$(CC) $^ $(LIB) $(FLAG) -o $(NAME)
${OBJ}/%.o : %.c
	@$(call CREATE,${OBJ})
	@printf "\rCub3D: building $@                      "
	@$(CC) -c $< -o $@ $(INCLUDE)
clean:
	$(call REMOVE,${OBJ})
	@$(MAKE) clean -C ./libft --silent
fclean: clean
	$(call REMOVE,${NAME})
	@$(MAKE) fclean -C ./libft --silent
re: fclean all
leak:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=codam.sup ./$(NAME) map.cub