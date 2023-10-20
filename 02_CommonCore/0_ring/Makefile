.PHONY: all clean fclean re

SRCS 	= ${wildcard *.c}
OBJS	= ${SRCS:.c=.o}
NAME 	= libft.a
COMP	= gcc
LIB		= ar rc
CFLAGS	= -Wall -Werror -Wextra

.c.o: 
			${COMP} ${CFLAGS} -c $< -o $@
	
${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS} 
		
all:		${NAME}

clean: 
			rm -f ${OBJS}

fclean: 	clean
			rm -f ${NAME}

re:			fclean all
