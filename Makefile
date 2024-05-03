NAME = libft.a

#Sources
INC =	-I inc
OBJS =	${PROJ:.c=.o}

#Compilation
CC =	cc
CFLAGS =	-Wall -Werror -Wextra
RM =	rm -f
AR =	ar rcs

#Librairy
LIBFT = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c

LIBFT_SRC = ${addprefix libft/, ${LIBFT}}

GNL = get_next_line_utils.c \
		get_next_line.c

GNL_SRC = ${addprefix gnl/, ${GNL}}

PRINTF = ft_print_tools.c \
			ft_printf.c \
			ft_print_hex.c \
			ft_print_unsigned.c \
			ft_print_ptr.c

PRINTF_SRC = ${addprefix printf/, ${PRINTF}}

PROJ = $(LIBFT_SRC) $(GNL_SRC) $(PRINTF_SRC)

#Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

#Phony
.PHONY : all clean fclean re
