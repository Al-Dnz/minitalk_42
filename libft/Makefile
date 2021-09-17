CC           = clang
HEADER		 = libft.h
CFLAGS       = -g3 -Wall -Wextra -Werror
NAME         = libft.a
SRCS         = ft_memset.c \
              ft_bzero.c \
              ft_memcpy.c \
              ft_memccpy.c \
              ft_memmove.c \
              ft_memchr.c \
              ft_memcmp.c \
              ft_strlen.c \
              ft_isalpha.c \
              ft_isdigit.c \
              ft_isalnum.c \
              ft_isascii.c \
              ft_isprint.c \
              ft_toupper.c \
              ft_tolower.c \
              ft_strchr.c \
              ft_strrchr.c \
              ft_strncmp.c \
              ft_strlcpy.c \
              ft_strlcat.c \
              ft_strnstr.c \
              ft_atoi.c \
              ft_calloc.c \
              ft_strdup.c \
              ft_substr.c \
              ft_strjoin.c \
              ft_strtrim.c \
              ft_split.c \
              ft_itoa.c \
              ft_strmapi.c \
              ft_putchar_fd.c \
              ft_putstr_fd.c \
              ft_putendl_fd.c \
              ft_putnbr_fd.c \
              get_next_line.c \
              get_next_line_util.c \
              ft_strcmp.c \
              ft_str_index.c \
              ft_tabsize.c \
              ft_free_tab.c \
              ft_is_sort.c \
              ft_is_supequal.c \
              ft_strchart.c \
              ft_find_index.c \
              ft_min.c \
              ft_max.c \
            ft_lstnew.c \
              ft_lstadd_front.c \
              ft_lstsize.c \
              ft_lstlast.c \
              ft_lstadd_back.c \
              ft_lstdelone.c \
              ft_lstclear.c \
              ft_lstiter.c \
              ft_lstmap.c \
              ft_lstpop.c \
              ft_del.c \
              ft_lstshift.c \
              ft_lstrev.c \
			  ft_lst_sort.c 

OBJS = 			${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}
	@echo "\n***********************"
	@echo "=> ${NAME} created !<="
	@echo "***********************"

all: ${NAME}

clean:
	rm -f ${OBJS}
	@echo "=> libft : obj cleant <="

fclean: clean
	rm -f ${NAME}
	@echo "=> ${NAME} cleant <="

re: fclean all
