CC	=				gcc

CFLAGS =			-Wall -Werror -Wextra

MLX_FLAGS =			-L $(MINILIBX_FOLDER) -lmlx -framework OpenGL -framework AppKit

RM =				rm -rf

NAME =				so_long

SRCS =				srcs/main.c

HEADERS =			headers/

LIBFT_FOLDER =		libs/libft/

MINILIBX_FOLDER =	libs/minilibx_opengl_20191021/

OBJS =				$(SRCS:.c=.o)

all:				$(NAME)

bonus:				all

compile_libraries:
						$(MAKE) -C $(LIBFT_FOLDER)
						$(MAKE) -C $(MINILIBX_FOLDER)

$(NAME):			compile_libraries $(OBJS)
						$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) -I $(HEADERS) -L $(LIBFT_FOLDER) -L $(MINILIBX_FOLDER) $(OBJS)

%.c.o:				%.c
						$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $(<:.c=.o)

clean:
						make clean -C $(LIBFT_FOLDER)
						make clean -C $(MINILIBX_FOLDER)
						$(RM) $(OBJS)

fclean:				clean
						make fclean -C $(LIBFT_FOLDER)
						$(RM) $(NAME)

re:					fclean	all

.PHONY:				all	clean	fclean	re
