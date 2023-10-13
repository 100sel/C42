VERBOSE ?= 

SRCS 	= ${wildcard srcs/*.c}

OBJS 	= ${SRCS:.c=.o}

NAME 	= libft.a

COMP 	= gcc

CFLAGS 	= -Wall -Wextra -Werror

.c.o: 	
			${VERBOSE}${COMP} ${CFLAGS} -c $< -o $@	

${NAME}:	${OBJS} 
			${VERBOSE}ar rc ${NAME} ${OBJS}

all:		${NAME}

clean: 
			${VERBOSE}rm -f ${OBJS}

fclean: 	clean
			${VERBOSE}rm ${NAME}

re:			fclean all

.PHONY:		all clean fclean re