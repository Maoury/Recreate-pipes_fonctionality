NAME 			:= pipex
FILES			:= close_fd.c create_fd_and_pipes.c executing_fork_and_main_process.c get_exec_binary.c get_the_path.c heredoc.c main.c manage_data.c action_on_files.c
SRCS			:= $(addprefix srcs/, $(FILES))
OBJS			:= $(SRCS:.c=.o)
DEPS			:= $(SRCS:.c=.d)

FILES_BONUS_1	:= close_fd.c create_fd_and_pipes.c executing_fork_and_main_process.c get_exec_binary.c get_the_path.c heredoc.c main1_bonus.c manage_data.c action_on_files.c
SRCS_BONUS_1	:= $(addprefix srcs/, $(FILES_BONUS_1))
OBJS_BONUS_1	:= $(SRCS_BONUS_1:.c=.o)
DEPS_BONUS_1	:= $(SRCS_BONUS_1:.c=.d)

FILES_BONUS_2	:= close_fd.c create_fd_and_pipes.c executing_fork_and_main_process.c get_exec_binary.c get_the_path.c heredoc.c main2_bonus.c manage_data.c action_on_files.c
SRCS_BONUS_2	:= $(addprefix srcs/, $(FILES_BONUS_2))
OBJS_BONUS_2	:= $(SRCS_BONUS_2:.c=.o)
DEPS_BONUS_2	:= $(SRCS_BONUS_2:.c=.d)

GNL_DIR			:= ./gnl
NAME_GNL		:= ${GNL_DIR}/gnl.a

LIBFT_DIR		:= ./libft
NAME_LIB		:= $(LIBFT_DIR)/libft.a

#-fsanitize=address -g3
CC				:= gcc
CFLAGS			:= -Wall -Werror -Wextra
DFLAGS			= -MMD -MF $(@:.o=.d)

all: $(NAME_LIB) $(NAME_GNL) $(OBJS) $(NAME)
-include $(DEPS)
-include $(DEPS_BONUS_2)
-include $(DEPS_BONUS_1)
$(NAME_LIB):
	@echo "LIBFT BUILDING BRU"
	@(cd $(LIBFT_DIR) && $(MAKE))

$(NAME_GNL):
	@(cd $(GNL_DIR) && $(MAKE))

$(NAME): $(OBJS) $(NAME_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(NAME_LIB) $(NAME_GNL) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(DFLAGS)


bonus_1: $(NAME_LIB) $(NAME_GNL) $(OBJS_BONUS_1) multipipex
		$(CC) $(CFLAGS) $(OBJS_BONUS_1) $(NAME_LIB) $(NAME_GNL) -o $(NAME)
		@touch bonus_1

multipipex:
		@mkdir -p multipipex

bonus_2: $(NAME_LIB) $(NAME_GNL) $(OBJS_BONUS_2) heredoc
		$(CC) $(CFLAGS) $(OBJS_BONUS_2) $(NAME_LIB) $(NAME_GNL) -o $(NAME)
		@touch bonus_2
heredoc:
		@(mkdir -p heredoc)

fclean: clean
	@(cd $(LIBFT_DIR) && make fclean)
	@(cd $(GNL_DIR) && make fclean)
	$(RM) $(NAME) ./multipipex/$(NAME) ./heredoc/$(NAME)

clean:
	@(cd $(LIBFT_DIR) && make clean)
	@(cd $(GNL_DIR) && make clean)
	$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS_1) $(DEPS_BONUS_1) $(OBJS_BONUS_2) $(DEPS_BONUS_2) bonus_1 bonus_2

re: fclean all

.PHONY: clean fclean re

