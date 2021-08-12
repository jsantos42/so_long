#   NOTE: FOR THIS TO WORK, CHANGE THE PROJECT'S RUNNING CONFIGURATIONS.
#   On the running configurations window, go the "Environment Variables"
#   field and add:
#          DYLD_LIBRARY_PATH=<path_to_dylib_folder>
#   Note that relative paths don't work! You can just get the absolute
#   path with the pwd command.

cmake_minimum_required(VERSION 3.17)
project(so_long C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "-Wall -Werror -Wextra -framework OpenGL -framework AppKit")

include_directories(include
        libs/libft
        libs/minilibx_mms_20200219
        srcs)

find_library(LIBMLX
        NAMES libmlx.dylib
        PATHS ./)

add_executable(so_long
        include/0_main.h
        include/8_hooks.h
        include/1_error_management.h
        include/3_map_importing.h
        include/4_get_next_line.h
        include/2_map_checking.h
        include/5_textures_loading.h
        include/9_move_player_and_update_position.h
        include/types.h
        include/6_map_printing.h
        include/7_put_to_window_img.h
        libs/libft/srcs/ft_atoi.c
        libs/libft/srcs/ft_bzero.c
        libs/libft/ft_calloc.c
        libs/libft/ft_isalnum.c
        libs/libft/ft_isalpha.c
        libs/libft/ft_isascii.c
        libs/libft/ft_isdigit.c
        libs/libft/ft_isprint.c
        libs/libft/ft_itoa.c
        libs/libft/ft_lstadd_back.c
        libs/libft/ft_lstadd_front.c
        libs/libft/ft_lstclear.c
        libs/libft/ft_lstdelone.c
        libs/libft/ft_lstiter.c
        libs/libft/ft_lstlast.c
        libs/libft/ft_lstmap.c
        libs/libft/ft_lstnew.c
        libs/libft/ft_lstsize.c
        libs/libft/ft_memccpy.c
        libs/libft/ft_memchr.c
        libs/libft/ft_memcmp.c
        libs/libft/ft_memcpy.c
        libs/libft/ft_memmove.c
        libs/libft/ft_memset.c
        libs/libft/ft_power.c
        libs/libft/ft_putchar_fd.c
        libs/libft/ft_putendl_fd.c
        libs/libft/ft_putnbr_fd.c
        libs/libft/ft_putstr_fd.c
        libs/libft/ft_split.c
        libs/libft/ft_strchr.c
        libs/libft/ft_strdup.c
        libs/libft/ft_strjoin.c
        libs/libft/ft_strlcat.c
        libs/libft/ft_strlcpy.c
        libs/libft/ft_strlen.c
        libs/libft/ft_strmapi.c
        libs/libft/ft_strncmp.c
        libs/libft/ft_strnstr.c
        libs/libft/ft_strrchr.c
        libs/libft/ft_strtrim.c
        libs/libft/ft_substr.c
        libs/libft/ft_tolower.c
        libs/libft/ft_toupper.c
        libs/libft/libft.h
        libs/minilibx_mms_20200219/mlx.h
        srcs/0_main.c
        srcs/8_hooks.c
        srcs/1_error_management.c
        srcs/3_map_importing.c
        srcs/4_get_next_line.c
        srcs/2_map_checking.c
        srcs/5_textures_loading.c
        srcs/9_move_player_and_update_position.c
        srcs/6_map_printing.c
        srcs/7_put_to_window_img.c)

target_link_libraries(so_long ${LIBMLX})
