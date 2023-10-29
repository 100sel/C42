.PHONY: make all run clean flcean re

NAME	= pipex

SRCS 	= ${wildcard *.c}
OBJS 	= ${SRCS:.c=.o}

COMP 	= gcc
FLAG 	= -g -Wall -Werror -Wextra

.c.o:
		${COMP} ${FLAG} -c $< -o $@

${NAME} : 	${OBJS}
			${COMP} -o ${NAME} ${OBJS}

all 	:	${NAME}

clean	:	
			rm -f ${OBJS}

fclean 	:	clean
			rm -f ${NOM}

re		:	fclean all

run 	:
			./${NAME} test1 "cat" "wc -l" test2

rerun	:	re run
