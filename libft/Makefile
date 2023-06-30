NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB = ar rcs

FILES =	ft_isalpha.c ft_isdigit.c\
		ft_isalnum.c ft_isascii.c\
		ft_isprint.c ft_strlen.c\
		ft_memset.c ft_bzero.c\
		ft_memcpy.c	ft_memmove.c\
		ft_strlcpy.c ft_strlcat.c\
		ft_toupper.c ft_tolower.c\
		ft_strchr.c	ft_strrchr.c\
		ft_strncmp.c ft_memchr.c\
		ft_memcmp.c	ft_strnstr.c\
		ft_atoi.c ft_calloc.c\
		ft_strdup.c ft_substr.c\
		ft_strjoin.c ft_strtrim.c\
		ft_itoa.c ft_strmapi.c\
		ft_striteri.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c\
		ft_putnbr_fd.c ft_split.c\
		ft_printf.c ft_print_char_string.c\
		ft_print_d_i_u.c ft_print_hex_ptr.c\
		struct.c write_flags.c\
		get_next_line_bonus.c get_next_line_utils_bonus.c\


BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c\
		ft_lstsize_bonus.c ft_lstlast_bonus.c\
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c ft_lstiter_bonus.c\
		ft_lstmap_bonus.c

OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

all : $(NAME)

$(NAME) :	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

$(OBJS) :	$(FILES)
			$(CC) $(FLAGS) -c $(FILES)

$(OBJS_BONUS) :	$(BONUS)
			$(CC) $(FLAGS) -c $(BONUS)

bonus : $(OBJS) $(OBJS_BONUS)
	$(LIB) $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean:
	rm -f $(NAME) $(OBJS) $(OBJS_BONUS)

re : fclean all

.PHONY : all re fclean clean bonus