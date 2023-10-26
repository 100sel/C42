.PHONY: all clean fclean re mck

SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}

LIBS = -L/usr/local/lib -lmlx -lXext -lX11 

NAME = so_long
MAP	 = maps/map.ber

COMP = gcc
FLAG = -g -Wall -Werror -Wextra

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

mck: 	
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --read-var-info=yes ./${NAME} ${MAP}

mrep:
		rm ${wildcard massif.out.*} && valgrind --tool=massif ./${NAME} ${MAP}
