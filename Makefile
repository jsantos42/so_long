CC	=				gcc
CFLAGS =			-Wall -Werror -Wextra
MLX_FLAGS =			-framework OpenGL -framework AppKit
RM =				rm -rf

NAME =				so_long
MINILIBX =			libmlx.dylib
INCLUDE =			include

SRCS_DIR = 			srcs
OBJS_DIR =			objs
LIBFT_DIR =			libs/libft
MINILIBX_DIR =		libs/minilibx_mms_20200219

SRCS =				$(wildcard $(SRCS_DIR)/*.c)
OBJS =				$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
LIBS =				$(LIBFT_DIR)/libft.a \
					libmlx.dylib

all:				$(NAME)

bonus:				all

compile_libraries:
						@$(MAKE) -C $(LIBFT_DIR)
						@$(MAKE) -C $(MINILIBX_DIR) --silent
						@mv $(MINILIBX_DIR)/$(MINILIBX) .
						@echo "$(MINILIBX) successfully compiled!"

$(OBJS_DIR)/%.o:	%.c
						@mkdir -p $(dir $@)
						@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(NAME):			compile_libraries $(OBJS)
						@$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) -I $(INCLUDE) $(LIBS) $(OBJS)
						@echo "$(NAME) successfully compiled!"

clean:
						@make clean -C $(LIBFT_DIR)
						@make clean -C $(MINILIBX_DIR) --silent
						@$(RM) $(OBJS_DIR)
						@echo "Successfuly cleaned all object files of $(NAME)!"

fclean:				clean
						@make fclean -C $(LIBFT_DIR)
						@$(RM) $(NAME) $(LIBS)
						@# There's no rule for fclean on the Makefile of MiniLibX.
						@echo "Successfuly cleaned all executable files of $(NAME)!"

re:					fclean	all

.PHONY:				all	clean	fclean	re
