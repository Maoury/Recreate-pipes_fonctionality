NAME	:= gnl.a

CC		:= gcc
FLAGS	:= -Wall -Wextra -Werror

SRCS	:= get_next_line.c get_next_line_utils.c
OBJS	:= ${SRCS:.c=.o}

GNL_LIB := ar -rcs

all: $(NAME)
%.o: %.c
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	${GNL_LIB} $(NAME) $(OBJS)

fclean: clean
	${RM} ${NAME}

clean:
	$(RM) $(OBJS)

re: fclean all
