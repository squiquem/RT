# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: squiquem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/23 19:01:27 by squiquem          #+#    #+#              #
#    Updated: 2019/02/25 18:38:27 by qsebasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY			:	all clean fclean re opti objects

NAME			=	RT

SRC_DIR			=	sources

OBJ_DIR			=	objects

SC				=	screenshots

INCPNG			=	-I ~/.brew/include/

CPPFLAGS 		=	-I includes/

INCLIB			=	-I libft/

INCMLX			=	-I minilibx/

SRC_FILES		=	main.c \
					handle/keyhook.c \
					handle/ui3_zone.c \
					handle/mousehook.c \
					handle/move.c \
					handle/param_zone.c \
					handle/ui_zone.c \
					hud/apply.c \
					hud/blur.c \
					hud/cursor.c \
					hud/fill_param.c \
					hud/general_ui.c \
					hud/hud.c \
					hud/init_hud.c \
					hud/loading.c \
					hud/new_image.c \
					hud/pick_item.c \
					hud/reset_ui.c \
					hud/ruler.c \
					hud/save_writting.c \
					hud/screenshot.c \
					hud/shade_bar.c \
					hud/spectrum_shade.c \
					hud/shape.c \
					hud/shape2.c \
					hud/ui1.c \
					hud/ui1_bottom.c \
					hud/ui2.c \
					hud/ui2_bottom.c \
					hud/ui3.c \
					hud/ui3_bottom.c \
					hud/ui3_writting.c \
					hud/util.c \
					maths/matrix.c \
					maths/rotate.c \
					maths/rotation_matrix.c \
					maths/vec.c \
					maths/vec2.c \
					parser/error.c \
					parser/get_position.c \
					parser/get_value_mat.c \
					parser/get_value_obj.c \
					parser/get_value_obj2.c \
					parser/get_value_obj3.c \
					parser/parser.c \
					parser/parser_all.c \
					parser/recup_camera.c \
					parser/recup_env.c \
					parser/recup_light.c \
					parser/recup_mat.c \
					parser/recup_mat2.c \
					parser/recup_object.c \
					parser/recup_object2.c \
					parser/recup_object3.c \
					parser/recursive_element.c \
					parser/recursive_elem2.c \
					parser/save.c \
					parser/save_light.c \
					parser/save_util.c \
					parser/save_material.c \
					parser/save_item.c \
					parser/set_zero_mat.c \
					render/aliasing.c \
					render/cartoon.c \
					render/checker.c \
					render/color.c \
					render/fct_to_add.c \
					render/filters.c \
					render/find_closest.c \
					render/find_closest2.c \
					render/find_normal.c \
					render/find_normal_plus.c \
					render/fresnel.c \
					render/hit_box.c \
					render/hit_disk.c \
					render/hit_func.c \
					render/hit_items.c \
					render/hit_items_plus.c \
					render/hsv.c \
					render/light.c \
					render/marble.c \
					render/negative_calc.c \
					render/negative_calc2.c \
					render/negative_calc3.c \
					render/new.c \
					render/noise.c \
					render/pixel.c \
					render/quadric.c \
					render/ray.c \
					render/shadow.c \
					render/tab.c \
					render/textures_util.c \
					render/textures.c \
					render/threads.c

SUB_FOLDERS		=	parser render hud handle maths

BUILD_DIR		=	$(addprefix $(OBJ_DIR)/,$(SUB_FOLDERS))

OBJ_FILES		=	$(SRC_FILES:.c=.o)

OBJ_D_FILES		=	$(SRC_FILES:.c=.d)

SRC				=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJ				=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

OBJ_D			=	$(addprefix $(OBJ_DIR)/, $(OBJ_D_FILES))

LFT				=	-L libft/ -lft

MLX				=	-L minilibx/ -lmlx -framework OpenGL -framework AppKit

LIBFT			=	libft/libft.a

LIBMLX			=	minilibx/libmlx.a

LPNG			=	-L ~/.brew/lib/ -lpng

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -MMD -O2

opti			:
	@make -j8 all

all				:	objects
	@make all -C libft/
	@make all -C minilibx/
	@make $(NAME)
	@mkdir -p $(SC)

objects			:	$(BUILD_DIR)

$(BUILD_DIR)	:
	@mkdir -p $@

$(NAME)			:	$(OBJ)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLIB) $(INCMLX) $(INCPNG) $(LFT) $(MLX) $(OBJ) $(LPNG) -o $@ 
	@printf '\033[4m'
	@printf "\033[32m[ ✔ ] $(NAME)\n\033[0m"
	@touch .gitignore
	@echo $(NAME) > .gitignore
	@echo $(SC) >> .gitignore

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c $(LIBFT) $(LIBMLX) $(LIBPNG)
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLIB) $(INCMLX) $(INCPNG) -o $@ -c $<
	@printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean			:
	@make fclean -C libft/
	@make clean -C minilibx/
	@rm -f $(OBJ)
	@rm -f $(OBJ_D)
	@rm -rf $(OBJ_DIR) 2> /dev/null || true
	@printf '\033[4m'
	@echo "\033[31m$(NAME):\033[0m"
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Object Files"

fclean			:	clean
	@rm -f $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Binary File"

re				:
	@make fclean
	@make opti

-include $(OBJ_D)
