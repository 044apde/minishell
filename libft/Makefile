NAME	= libft.a
CC		= cc
CFLAGS  = -Wall -Wextra -Werror
AR		= ar
ARFLAGS = -rc
INC		= ./libft.h
SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_B  = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ_FILES	= $(SRCS:.c=.o)
OBJ_FILES_B = $(SRCS_B:.c=.o)
 
all : $(NAME)

basic_file: $(OBJS_FILES)
	rm -rf bonus_file
	$(AR) $(ARFLAGS) $(NAME) $^
	touch $@

bonus: bonus_file

bonus_file : $(OBJ_FILES_B) $(OBJ_FILES)
	rm -rf basic_file
	$(AR) $(ARFLAGS) $(NAME) $^
	touch $@

clean :
	rm -f $(OBJ_FILES) $(OBJ_FILES_B) bonus_file basic_file

fclean : clean
	rm -f $(NAME) bonus_file basic_file

re :
	make fclean
	make all

$(NAME) : $(OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $?

.PHONY : all bonus clean fclean re