.PHONY: all clean fclean re

S_SRCS = ${S_NAME}.c
C_SRCS = ${C_NAME}.c

S_OBJS = ${S_SRCS:.c=.o}
C_OBJS = ${C_SRCS:.c=.o}

S_NAME = server
C_NAME = client

COMP = gcc
CFLAGS = -g -Wall -Wextra -Werror 

.c.o:
		${COMP} ${CFLAGS} -c $< -o $@

${S_NAME}: ${S_OBJS}
		${COMP} -o ${S_NAME} ${S_OBJS}

${C_NAME}: ${C_OBJS}
		${COMP} -o ${C_NAME} ${C_OBJS}

all: ${S_NAME} ${C_NAME}

clean:
	rm -f ${S_OBJS} ${C_OBJS}

fclean: clean
	rm -f ${S_NAME} ${C_NAME}

re:	fclean all
