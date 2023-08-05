TARGET		=	minishell
CC			=	cc -g
CFLAGS		=	
LDFLAGS		=	-L${HOME}/.brew/opt/readline/lib -lreadline
CFALG		=	-I${HOME}/.brew/opt/readline/include
SOURCE		=	main.c src/read_input.c src/sig_handler.c src/term.c src/utils1.c src/init_minishell.c \
				src/parse/parse_input.c src/split/split.c src/split/split_utils.c src/split/split_utils2.c \
				src/split/split_utils3.c src/parse/parse_utils.c src/parse/parse_utils2.c src/parse/parse_utils3.c \
				src/execute_token/execute_token.c src/env/save_envp_list.c src/execute_token/execute_utils.c \
				src/execute_token/execute_utils2.c src/execute_token/execute_utils3.c src/execute_token/execute_utils4.c \
				src/execute_token/execute_utils5.c src/env/env_utils.c src/execute_token/execute_utils6.c src/builtin/excute_builtin.c \
				src/builtin/cd.c src/builtin/echo.c src/builtin/env.c src/builtin/exit.c src/builtin/export.c src/builtin/pwd.c src/builtin/unset.c \
				src/builtin/export_utils.c src/builtin/export_utils2.c src/split/split_utils4.c

HEADER		=	minishell.h
LIBRARY 	=	libft/libft.a

all			:	$(TARGET)

$(TARGET)	:	$(SOURCE) $(LIBRARY) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(SOURCE) $(LIBRARY) $(LDFLAGS) $(CFALG)

$(LIBRARY):
	$(MAKE) -C libft

clean		:
	rm -rf $(TARGET)
	$(MAKE) -C libft clean

fclean		:	clean
	$(MAKE) -C libft fclean

re			:	fclean all

.PHONY		:	all clean fclean re $(TARGET) $(LIBRARY)