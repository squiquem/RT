# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: squiquem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 19:01:27 by squiquem          #+#    #+#              #
#    Updated: 2019/03/04 21:26:11 by squiquem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY			=	all clean fclean re opti

NAME			=	libft.a

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

SRC_FILES		=	ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memccpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strlen.c \
					ft_strdup.c \
					ft_strcpy.c \
					ft_strncpy.c \
					ft_strcat.c \
					ft_strncat.c \
					ft_strlcat.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strstr.c \
					ft_strnstr.c \
					ft_strcmp.c \
					ft_strncmp.c \
					ft_atoi.c \
					ft_atoi_base.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_memalloc.c \
					ft_memdel.c \
					ft_strnew.c \
					ft_strdel.c \
					ft_strclr.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strequ.c \
					ft_strnequ.c \
					ft_strsub.c \
					ft_strjoin.c \
					ft_strnjoin.c \
					ft_strtrim.c \
					ft_strsplit.c \
					ft_itoa.c \
					ft_ltoa.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_putendl.c \
					ft_putnbr.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_lstnew.c \
					ft_lstdelone.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstaddtail.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_lstfind.c \
					ft_lstremoveif.c \
					ft_lstdelif.c \
					ft_strrev.c \
					ft_swap.c \
					ft_sqrt.c \
					ft_whitespace.c \
					ft_is_prime.c \
					ft_lerp.c \
					ft_lerpi.c \
					get_next_line.c \
					ft_lstlen.c \
					ft_freesplit.c \
					ft_printerror.c \
					ft_min.c \
					ft_max.c \
					ft_abs.c \
					ft_clamp.c \
					ft_strjoinfree.c \
					ft_strsubf.c \
					ft_fade.c

OBJ_FILES		=	$(SRC_FILES:.c=.o)

OBJ_DIR			=	./obj/

OBJ				=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

opti			:
	@make -j8 all

all				:	$(NAME)

$(NAME)			: 	$(OBJ)
	@ar -rcs $@ $^
	@printf '\033[4m'
	@echo "\033[32m\n[ ✔ ] Libft\033[0m"

$(OBJ_DIR)%.o	: 	%.c libft.h
	@echo "\033[94;1m\c"
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo -n █

clean			:
	@rm -f $(OBJ)
	@rmdir $(OBJ_DIR) 2> /dev/null || true
	@printf '\033[4m'
	@echo "\033[31mLibft:\033[0m"
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Object Files"
	
fclean			:	clean
	@rm -f $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Binary File"

re				:
	@make fclean
	@make opti
