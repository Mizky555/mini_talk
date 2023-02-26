SRCS1			= server.c
SRCS2			= client.c

OBJS1			= $(SRCS1:.c=.o)
OBJS2			= $(SRCS2:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME1			= server
NAME2			= client

all:			$(NAME1) $(NAME2)

$(NAME1):		$(OBJS1)
					$(CC) $(CFLAGS) -o $(NAME1) $(OBJS1)

$(NAME2):		$(OBJS2)
					$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2)

clean:
					$(RM) $(OBJS1) $(OBJS2)

fclean:			clean
					$(RM) $(NAME1) $(NAME2)

re:				fclean $(NAME1) $(NAME2)

.PHONY:			all clean fclean re
