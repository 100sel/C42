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

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

all:		${NAME} 

re:			fclean all 
			rm -f ${OBJS}
run: 		
			./${NAME}

rerun: 		re run
			
