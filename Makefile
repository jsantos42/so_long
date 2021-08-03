CC	=				gcc

CFLAGS =			-Wall -Werror -Wextra

MLX_FLAGS =			-framework OpenGL -framework AppKit

RM =				rm -rf

NAME =				so_long

INCLUDE =			include

SRCS =				$(wildcard srcs/*.c)

LIBFT_FOLDER =		libs/libft

MINILIBX_FOLDER =	libs/minilibx_mms_20200219

LIBS =				$(LIBFT_FOLDER)/libft.a \
					libmlx.dylib

OBJS =				$(SRCS:.c=.o)

all:				$(NAME)

bonus:				all

compile_libraries:
						$(MAKE) -C $(LIBFT_FOLDER)
						$(MAKE) -C $(MINILIBX_FOLDER)
						mv $(MINILIBX_FOLDER)/libmlx.dylib .

$(NAME):			compile_libraries $(OBJS)
						$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) -I $(INCLUDE) $(LIBS) $(OBJS)

%.c.o:				%.c
						$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

clean:
						make clean -C $(LIBFT_FOLDER)
						make clean -C $(MINILIBX_FOLDER)
						$(RM) $(OBJS)

fclean:				clean
						make fclean -C $(LIBFT_FOLDER)
						$(RM) $(NAME) $(LIBS)

re:					fclean	all

.PHONY:				all	clean	fclean	re
