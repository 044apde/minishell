TARGET		= minishell

CC			= cc
LDFLAGS		= -L${HOME}/.brew/opt/readline/lib -lreadline
CPPFLAGS	= -I${HOME}/.brew/opt/readline/include

SOURCE	= main.c src/read_input.c src/sig_handler.c
HEADER	= minishell.h

LIBRARY = libft/libft.a

all			:	$(TARGET)

$(TARGET)	:	$(SOURCE) $(LIBRARY)
	$(CC) -o $@ $(SOURCE) $(LIBRARY) $(LDFLAGS) $(CPPFLAGS)

$(LIBRARY):
	$(MAKE) -C libft

clean		:
	rm -rf $(TARGET)