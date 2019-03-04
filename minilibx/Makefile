# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: squiquem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 03:56:37 by squiquem          #+#    #+#              #
#    Updated: 2018/09/20 19:45:58 by qsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOM		=	libmlx.a

CC		=	cc

CFLAGS+	=	-O2

SRC		=	mlx_shaders.c \
			mlx_new_window.m \
			mlx_init_loop.m \
			mlx_new_image.m \
			mlx_xpm.c \
			mlx_int_str_to_wordtab.c \

OBJ1	=	$(SRC:.c=.o)

OBJ		=	$(OBJ1:.m=.o)

all		:	$(NOM)

$(NOM)	:	$(OBJ)
	@ar -rcs $@ $^
	@printf '\033[4m'
	@echo "\033[32m\n[ ✔ ] Mlx\033[0m"
	
%.o		:	%.c
	@echo "\033[94;1m\c"
	@$(CC) $(CFLAGS+) -c -o $@ $<
	@echo -n █
#	@echo "\033[0m\c"

%.o		:	%.m
	@echo "\033[94;1m\c"
	@$(CC) $(CFLAGS+) -c -o $@ $<
	@echo -n █
#	@echo "\033[0m\c"

clean	:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app
	@printf '\033[4m'
	@echo "\033[31mMlx:\033[0m"
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Object Files"
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Binary File"

re		:	clean all
