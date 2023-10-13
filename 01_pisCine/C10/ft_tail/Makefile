VERBOSE ?= 

SRCS 	= ${wildcard *.c}

OBJS 	= ${SRCS:.c=.o}

NAME 	= ft_tail

COMP 	= gcc

CFLAGS 	= -Wall -Wextra -Werror -g

LIB 	= -L. -lft

.c.o: 	
			${VERBOSE}${COMP} ${CFLAGS} -c $< -o $@	

${NAME}:	${OBJS} 
			${VERBOSE}${COMP} -o ${NAME} ${OBJS} ${LIB}

all:		${NAME}

clean: 
			${VERBOSE}rm -f ${OBJS}

fclean: 	clean
			${VERBOSE}rm ${NAME}

re:			fclean all

.PHONY:		all clean fclean re