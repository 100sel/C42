.PHONY: all clean fclean re

SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}
NAME = get_next_line.exe
COMP = gcc
CFLAGS = -g -Wall -Werror -Wextra -D BUFFER_SIZE=42

.c.o:
		${COMP} ${CFLAGS} -c $< -o $@

${NAME}:${OBJS}
		${COMP} -o ${NAME} ${OBJS}

all:	${NAME}		

clean: 
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: 	fclean all