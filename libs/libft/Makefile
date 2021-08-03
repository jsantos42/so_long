CC =		gcc

CFLAGS =	-Wall -Werror -Wextra

RM =		rm -fr

NAME =		libft.a

INCLUDE =	libft.h

SRCS =		$(wildcard *.c)

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
				ar -rcs $(NAME) $(OBJS)

%.c.o: %.c
				$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

clean:
				$(RM) *.o

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all	bonus	clean	fclean	re	rebonus
