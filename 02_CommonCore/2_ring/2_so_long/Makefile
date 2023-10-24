.PHONY: all clean fclean re

SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}

LIBS = -L/usr/local/lib -lmlx -lXext -lX11 

NAME = so_long

COMP = gcc
FLAG = -g

.c.o: 
		${COMP} ${FLAG} -c $< -o $@

${NAME}: ${OBJS}
		${COMP} -o ${NAME} ${OBJS} ${LIBS}

all:	${NAME}

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:		fclean all
