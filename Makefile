TARGET		= minishell

CC			= cc
LDFLAGS		= -L/Users/shikim/.brew/opt/readline/lib -lreadline
CPPFLAGS	= -I/Users/shikim/.brew/opt/readline/include

SOURCE	= main.c src/read_input.c src/sig_handler.c
HEADER	= minishell.h

LIBRARY = libft/libft.a

all			:	$(TARGET)

$(TARGET)	:	$(SOURCE) $(LIBRARY)
	$(CC) -o $@ $(SOURCE) $(LIBRARY) $(LDFLAGS) $(CPPFLAGS)

$(LIBRARY):
	$(MAKE) -C libft
	$(MAKE) -C ft_printf

clean		:
	rm -rf $(TARGET)