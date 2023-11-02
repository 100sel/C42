.PHONY: all clean fclean re run rerun

NAME = minishell

SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}

COMP = gcc
FLAG = -g -Wall -Werror -Wextra

.c.o:
			${COMP} ${FLAG} -c $< -o $@

${NAME}:	${OBJS}	
			${COMP} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

run: 		
			./${NAME}

rerun: 		re run
			
