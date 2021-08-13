#   NOTE: FOR THIS TO RUN, CHANGE THE PROJECT'S RUNNING CONFIGURATIONS.
#   On the running configurations window of both CMake targets:
#   1) set the "Environment Variables" to DYLD_LIBRARY_PATH=<path_to_dylib_folder>
#   2) set the "Working Directory" to the absolute path of your project root folder
#   Note that relative paths don't work! You can just get the absolute
#   path with the pwd command.
#   Also, the .c files of the MiniLibX can't be inside the add_executable
#   rule, otherwise it will raise a lot of warnings.

cmake_minimum_required(VERSION 3.17)
project(so_long C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_C_FLAGS}" -framework OpenGL -framework AppKit")

include_directories(include
        libs/libft
        libs/minilibx_mms_20200219
        srcs)

find_library(LIBMLX
        NAMES libmlx.dylib
        PATHS ./)

set(FILES
        include/0_main.h
        include/1_error_management.h
        include/2_map_checking.h
        include/3_map_importing.h
        include/4_get_next_line.h
        include/5_textures_loading.h
        include/6_map_printing.h
        include/7_put_to_window_img.h
        include/8_hooks.h
        include/9_move_player_and_update_position.h
        include/types.h
        libs/libft/include/libft.h
        libs/libft/srcs/change_case/ft_tolower.c
        libs/libft/srcs/change_case/ft_toupper.c
        libs/libft/srcs/is/ft_isalnum.c
        libs/libft/srcs/is/ft_isalpha.c
        libs/libft/srcs/is/ft_isascii.c
        libs/libft/srcs/is/ft_isdigit.c
        libs/libft/srcs/is/ft_isprint.c
        libs/libft/srcs/lst/ft_lstadd_back.c
        libs/libft/srcs/lst/ft_lstadd_front.c
        libs/libft/srcs/lst/ft_lstclear.c
        libs/libft/srcs/lst/ft_lstdelone.c
        libs/libft/srcs/lst/ft_lstiter.c
        libs/libft/srcs/lst/ft_lstlast.c
        libs/libft/srcs/lst/ft_lstmap.c
        libs/libft/srcs/lst/ft_lstnew.c
        libs/libft/srcs/lst/ft_lstsize.c
        libs/libft/srcs/math/ft_abs.c
        libs/libft/srcs/math/ft_power.c
        libs/libft/srcs/mem/ft_bzero.c
        libs/libft/srcs/mem/ft_calloc.c
        libs/libft/srcs/mem/ft_memccpy.c
        libs/libft/srcs/mem/ft_memchr.c
        libs/libft/srcs/mem/ft_memcmp.c
        libs/libft/srcs/mem/ft_memcpy.c
        libs/libft/srcs/mem/ft_memmove.c
        libs/libft/srcs/mem/ft_memset.c
        libs/libft/srcs/put/ft_putchar_fd.c
        libs/libft/srcs/put/ft_putendl_fd.c
        libs/libft/srcs/put/ft_putnbr_fd.c
        libs/libft/srcs/put/ft_putstr_fd.c
        libs/libft/srcs/stack/stack_bottom.c
        libs/libft/srcs/stack/stack_clear.c
        libs/libft/srcs/stack/stack_new.c
        libs/libft/srcs/stack/stack_pop.c
        libs/libft/srcs/stack/stack_push.c
        libs/libft/srcs/stack/stack_size.c
        libs/libft/srcs/str/ft_split.c
        libs/libft/srcs/str/ft_str_eraser.c
        libs/libft/srcs/str/ft_strchr.c
        libs/libft/srcs/str/ft_strdup.c
        libs/libft/srcs/str/ft_strjoin.c
        libs/libft/srcs/str/ft_strlcat.c
        libs/libft/srcs/str/ft_strlcpy.c
        libs/libft/srcs/str/ft_strlen.c
        libs/libft/srcs/str/ft_strmapi.c
        libs/libft/srcs/str/ft_strncmp.c
        libs/libft/srcs/str/ft_strnstr.c
        libs/libft/srcs/str/ft_strrchr.c
        libs/libft/srcs/str/ft_strtrim.c
        libs/libft/srcs/str/ft_substr.c
        libs/libft/srcs/type_conversion/ft_atoi.c
        libs/libft/srcs/type_conversion/ft_itoa.c
        libs/minilibx_mms_20200219/mlx.h
        srcs/0_main.c
        srcs/1_error_management.c
        srcs/2_map_checking.c
        srcs/3_map_importing.c
        srcs/4_get_next_line.c
        srcs/5_textures_loading.c
        srcs/6_map_printing.c
        srcs/7_put_to_window_img.c
        srcs/8_hooks.c
        srcs/9_move_player_and_update_position.c)

add_executable(so_long_mandatory ${FILES})
target_link_libraries(so_long_mandatory ${LIBMLX})
set_target_properties(so_long_mandatory PROPERTIES COMPILE_FLAGS "-D BONUS=0")

add_executable(so_long_bonus ${FILES})
target_link_libraries(so_long_bonus ${LIBMLX})
set_target_properties(so_long_bonus PROPERTIES COMPILE_FLAGS "-D BONUS=1")
