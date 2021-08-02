CC =							gcc

CFLAGS =					-Wall -Werror -Wextra

RM =							rm -fr

NAME =						libft.a

INCLUDE =					libft.h

SRCS_MANDATORY =	ft_atoi.c		    ft_bzero.c		  ft_calloc.c		\
									ft_isalnum.c	  ft_isalpha.c	  ft_isascii.c	\
									ft_isdigit.c	  ft_isprint.c  	ft_itoa.c		\
									ft_memccpy.c	  ft_memchr.c	  	ft_memcmp.c		\
									ft_memcpy.c		  ft_memmove.c  	ft_memset.c		\
									ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
									ft_putstr_fd.c	ft_split.c	  	ft_strchr.c		\
									ft_strdup.c		  ft_strjoin.c  	ft_strlcat.c	\
									ft_strlcpy.c	  ft_strlen.c	  	ft_strmapi.c	\
									ft_strncmp.c	  ft_strnstr.c  	ft_strrchr.c	\
									ft_strtrim.c	  ft_substr.c	  	ft_tolower.c	\
									ft_toupper.c


SRCS_BONUS =			ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c	\
									ft_lstdelone.c		ft_lstiter.c  		ft_lstlast.c	\
									ft_lstmap.c 			ft_lstnew.c		  	ft_lstsize.c

OBJS_MANDATORY =	$(SRCS_MANDATORY:.c=.o)

OBJS_BONUS =			$(SRCS_BONUS:.c=.o)

all:							$(NAME)

$(NAME):					$(OBJS_MANDATORY) $(INCLUDE)
											ar -rcs $(NAME) $(OBJS_MANDATORY)


bonus:						$(OBJS_BONUS) $(INCLUDE)
											ar -rcs $(NAME) $(OBJS_BONUS)


%.c.o: %.c
											$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)


clean:
											$(RM) *.o

fclean:						clean
											$(RM) $(NAME)

re:								fclean all

rebonus:					fclean bonus

.PHONY:						all	bonus	clean	fclean	re	rebonus