# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <allallem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/25 14:33:47 by allallem          #+#    #+#              #
#    Updated: 2019/05/25 14:33:48 by allallem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libui.a

OBJDIR = objets/

LIB_PATH = libft/includes/

HEADER = includes/

SRCDIR = sources/

SRC		= ft_close_sdl.c\
				ft_create_renderer.c\
				ft_create_surface.c\
				ft_create_window.c\
				ft_get_color.c\
				ft_init.c\
				ft_update_window.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER) -I $(LIB_PATH) -I$(HOME)/.brew/include/SDL2

DEB =  -fsanitize=address -g

DEL		=	rm -f

LIB		= -L libft -lft -L$(HOME)/.brew/lib -lSDL2 -lSDL2_mixer -lSDL2_ttf

all: init $(NAME)

init:
	@mkdir -p $(OBJDIR)

norme:
	make -C libft norme
	norminette $(SRCDIR) $(HEADER)

install:
	brew reinstall SDL2 && brew reinstall SDL2_MIXER && brew reinstall sdl2_ttf

debug	:	fclean
	make DEBUG=1

re:fclean all

$(NAME):$(OBJ)
	make -C libft
	@ar rc $(NAME) $^

$(OBJDIR)%.o:$(SRCDIR)%.c
ifdef DEBUG
	$(CC) $(CFLAGS) $(DEB) -c $^ -o $@
else
	$(CC) $(CFLAGS) -c $^ -o $@
endif

lldb:
	$(CC) -o $(NAME) $(SRCS) $^ $(CFLAGS) $(DEB) $(LIB) $(LIBX)

fclean:clean
	@make -C libft fclean
	@$(DEL) $(NAME)

clean:
	@$(DEL) $(OBJ)
