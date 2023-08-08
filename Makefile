# 변수 설정
TARGET = minishell
CC = cc
CFLAGS = 
RHSOURCE = -L${HOME}/.brew/opt/readline/lib -lreadline
RHEADER = -I${HOME}/.brew/opt/readline/include
SOURCE = main.c src/read_input.c src/sig_handler.c src/term.c src/utils1.c \
         src/init_minishell.c src/parse/parse_input.c src/split/split.c \
         src/split/split_utils.c src/split/split_utils2.c src/split/split_utils3.c \
         src/parse/parse_utils.c src/parse/parse_utils2.c src/parse/parse_utils3.c \
         src/execute_token/execute_token.c src/env/save_envp_list.c \
         src/execute_token/execute_utils.c src/execute_token/execute_utils2.c \
         src/execute_token/execute_utils3.c src/execute_token/execute_utils4.c \
         src/execute_token/execute_utils5.c src/env/env_utils.c \
         src/execute_token/execute_utils6.c src/builtin/excute_builtin.c \
         src/builtin/cd.c src/builtin/echo.c src/builtin/env.c src/builtin/exit.c \
         src/builtin/export.c src/builtin/pwd.c src/builtin/unset.c \
         src/builtin/export_utils.c src/builtin/export_utils2.c \
         src/split/split_utils4.c src/parse/parse_utils4.c
HEADER = minishell.h
LIBRARY = libft/libft.a

# 기본 타겟
all: $(TARGET)

# 타겟 빌드 규칙
$(TARGET): $(SOURCE) $(LIBRARY) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(SOURCE) $(LIBRARY) $(RHSOURCE) $(RHEADER)

# 서브 타겟(libft) 빌드 규칙
$(LIBRARY):
	$(MAKE) -C libft

# 클린업 규칙
clean:
	rm -rf $(TARGET)
	$(MAKE) -C libft clean

# 완전한 클린업 규칙
fclean: clean
	$(MAKE) -C libft fclean

# 재빌드 규칙
re: fclean all

# .PHONY 설정
.PHONY: all clean fclean re $(TARGET) $(LIBRARY)
