npipes.c close_fd.c create_fd_and_pipes.c 
executing_fork_and_main_process.c action_on_files.c

NAME = libft.a

CC = gcc

FLAGS   = -Wall -Wextra -Werror

DEL = /bin/rm -f

SRCS =  



SRCS_O  = ${SRCS:.c=.o}

BONUS_O = ${BONUS:.c=.o}
all:	$(NAME)

LIBC    = ar -rcs

%.o: %.c
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${SRCS_O}
	${LIBC} $(NAME) $(SRCS_O)

bonus: $(SRCS_O) $(BONUS_O)
	$(LIBC) $(NAME) $(SRCS_O) $(BONUS_O)

fclean: clean
	$(DEL) $(NAME)

clean:
	$(DEL) $(SRCS_O) $(BONUS_O)

re: fclean all
