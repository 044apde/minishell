TARGET		=	minishell
CC			=	cc
LDFLAGS		=	-L${HOME}/.brew/opt/readline/lib -lreadline
CFALG		=	-I${HOME}/.brew/opt/readline/include
SOURCE		=	main.c src/read_input.c src/sig_handler.c src/term.c src/utils1.c src/init_minishell.c
HEADER		=	minishell.h
LIBRARY 	=	libft/libft.a

all			:	$(TARGET)

$(TARGET)	:	$(SOURCE) $(LIBRARY) $(HEADER)
	$(CC) -o $@ $(SOURCE) $(LIBRARY) $(LDFLAGS) $(CFALG)

$(LIBRARY):
	$(MAKE) -C libft

clean		:
	rm -rf $(TARGET)
	$(MAKE) -C libft clean

fclean		:	clean
	$(MAKE) -C libft fclean

re			:	fclean all

.PHONY		:	all clean fclean re $(TARGET) $(LIBRARY)