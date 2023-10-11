NAME			=	cub3d
ifeq ($(shell uname), Darwin)
	CFLAGS			=	-Wall -Werror -Wextra
	INCLUDE			=	-DEBUG=1 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
	
else
	CFLAGS			=	-Wall -Werror -ldl -Wextra
	INCLUDE			=	-DEBUG=1 -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
endif
RM				=	rm -fr
DIR_MAKE_MLX	=	./MLX42
DIR_SRC			=	./source/
#DIR_GNL			=	./Get_Next_Line/
#SRC				=	$(DIR_GNL)get_next_line_utils.c $(DIR_GNL)get_next_line.c
SRC				= 	$(DIR_SRC)get_next_line.c $(DIR_SRC)get_next_line_utils.c \
					$(DIR_SRC)main.c $(DIR_SRC)ft_utils.c $(DIR_SRC)ft_read_check.c \
					$(DIR_SRC)ft_check_map.c $(DIR_SRC)ft_check_map_format.c \
					$(DIR_SRC)ft_hooks.c $(DIR_SRC)minimap.c $(DIR_SRC)ray.c
# COLORS
GREEN = `tput setaf 2`
RED = `tput setaf 1`
RESET = `tput sgr0`

$(TRUE).SILENT:

OBJ				=	$(SRC:.c=.o)

all: make_mlx $(NAME)

make_mlx:
			@$(MAKE) -C $(DIR_MAKE_MLX)

$(NAME):	$(OBJ)
			@gcc $(CFLAGS) $(SRC) -o $(NAME) $(DIR_MAKE_MLX)/libmlx42.a $(INCLUDE)
			@echo "$(GREEN)CREATE $(NAME)$(RESET)"

re:		fclean all

clean:
		@$(MAKE) -s clean -C $(DIR_MAKE_MLX)
		@$(RM) $(OBJ)
		@echo "$(RED)REMOVE OBJECTS $(NAME)$(RESET)\n"

fclean:		clean
			@$(MAKE) -s fclean -C $(DIR_MAKE_MLX)
			@$(RM) $(NAME) $(NAME).dSYM
			@echo "$(RED)DELETE $(NAME)$(RESET)\n"

.PHONY: 	all make_mlx re clean fclean
