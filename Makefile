# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <allallem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/25 14:33:47 by allallem          #+#    #+#              #
#    Updated: 2019/09/02 16:45:32 by allallem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	scop

LIBUI_PATH = libui/includes/

LIB_PATH = libui/libft/includes/

SRCDIR = sources/

OBJDIR = objets/

HEADER = includes/

SRC		= main.c\
				ft_allocate_env.c\
				ft_fill_env.c\
				tests_functions.c\
				ft_scop.c\
				ft_run.c\
				ft_keys_event.c\
				ft_mat4_multiplication.c\
				ft_update_opengl.c\
				ft_shader_functions.c\
				ft_load_source.c\
				ft_average.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER) -I $(LIB_PATH) -I $(LIBUI_PATH) -I$(HOME)/.brew/include/SDL2 -I$(HOME)/.brew/Cellar/glew/2.1.0/include

DEB =  -fsanitize=address -g

DEL		=	rm -f

LIB		= -L libui/libft -L libui -lft -lui -L$(HOME)/.brew/lib -L$(HOME)/.brew/Cellar/glew/2.1.0/lib -lSDL2 -lSDL2_mixer -lSDL2_ttf -lSDL2_image -framework OpenGL -lglew

all: init $(NAME)

norme:
	make -C libui norme
	norminette $(SRCDIR) $(HEADER)

install:
	brew reinstall SDL2 && brew reinstall SDL2_MIXER && brew reinstall sdl2_ttf

debug	:	fclean
	make DEBUG=1

re:fclean all

$(NAME): $(OBJ)
	make -C libui
ifdef DEBUG
	$(CC) -o $(NAME) $^ $(CFLAGS) $(DEB) $(LIB) $(LIBX)
else
	$(CC) -o $(NAME) $^ $(CFLAGS) $(LIB) $(LIBX)
endif
	clear
	@echo "Successful Compilation"

$(OBJDIR)%.o:$(SRCDIR)%.c
ifdef DEBUG
	$(CC) $(CFLAGS) $(DEB) -c $^ -o $@
else
	$(CC) $(CFLAGS) -c $^ -o $@
endif

init:
	@mkdir -p $(OBJDIR)

lldb:
	$(CC) -o $(NAME) $(SRCS) $^ $(CFLAGS) $(DEB) $(LIB) $(LIBX)

fclean:clean
	make -C libui fclean
	$(DEL) $(NAME)

clean:
	@$(DEL) $(OBJ)
