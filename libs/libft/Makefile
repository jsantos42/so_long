CC =				gcc
CFLAGS =			-Wall -Werror -Wextra
RM =				rm -fr

NAME =				libft.a
INCLUDE =			include

SRCS_DIR =			srcs
OBJS_DIR =			objs

SRCS =				$(wildcard $(SRCS_DIR)/*/*.c)
OBJS =				$(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all:				$(NAME)

$(NAME):			$(OBJS)
						@ar -rcs $(NAME) $(OBJS)
						@echo "$(NAME) successfully compiled!\n"

$(OBJS_DIR)/%.o:	%.c
						@mkdir -p $(dir $@)
						@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
						$(RM) $(OBJS_DIR)

fclean:				clean
						$(RM) $(NAME)

re:					fclean all

rebonus:			fclean bonus

.PHONY:				all	bonus	clean	fclean	re	rebonus
