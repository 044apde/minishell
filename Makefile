TARGET	= minishell

CC		= cc
CLFAG	= -I/usr/local/include -L/usr/local/lib -lreadline

SOURCE	= main.c src/read_input.c src/sig_handler.c
HEADER	= minishell.h

LIBRARY = libft/libft.a

all			:	$(TARGET)

$(TARGET)	:	$(SOURCE) $(LIBRARY)
	$(CC) $(CLFAG) -o $@ $(SOURCE) $(LIBRARY)

$(LIBRARY):
	$(MAKE) -C libft
	$(MAKE) -C ft_printf

clean		:
	rm -rf $(TARGET)