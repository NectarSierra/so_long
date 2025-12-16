CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f
NAME = libft.a
DEPS = libft.h
SRCS = ft_strnstr.c\
	   ft_strchr.c\
	   ft_isprint.c\
	   ft_bzero.c\
	   ft_strncmp.c\
	   ft_memset.c\
	   ft_isdigit.c\
	   ft_atoi.c\
	   ft_strlen.c\
   	   ft_memmove.c\
	   ft_isascii.c\
	   ft_toupper.c\
	   ft_strlcpy.c\
	   ft_memcpy.c\
	   ft_isalpha.c\
	   ft_tolower.c\
	   ft_strlcat.c\
	   ft_memcmp.c\
	   ft_isalnum.c\
	   ft_strrchr.c\
	   ft_strdup.c\
	   ft_memchr.c\
	   ft_calloc.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_striteri.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew_bonus.c\
			 ft_lstadd_front_bonus.c\
			 ft_lstsize_bonus.c\
			 ft_lstlast_bonus.c\
			 ft_lstadd_back_bonus.c\
			 ft_lstdelone_bonus.c\
			 ft_lstclear_bonus.c\
			 ft_lstiter_bonus.c\
			 ft_lstmap_bonus.c\
			./gnl/get_next_line.c\
			./gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	-@$(AR) $@ $^

bonus: $(OBJS) $(OBJS_BONUS)
	-@$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: bonus all clean fclean re
