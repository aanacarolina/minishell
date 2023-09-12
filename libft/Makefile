# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 19:45:45 by gacalaza          #+#    #+#              #
#    Updated: 2023/04/15 15:07:15 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ======= COLORS ========
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
END_COL = \033[0m

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c
SRCS += ft_memcpy.c ft_memset.c ft_memmove.c ft_memcmp.c ft_memchr.c
SRCS += ft_strchr.c ft_strrchr.c ft_strlen.c ft_bzero.c ft_strncmp.c ft_atoi.c
SRCS += ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_strdup.c
SRCS += ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_putstr_fd.c ft_itoa.c
SRCS += ft_substr.c ft_strjoin.c ft_strmapi.c ft_striteri.c ft_strtrim.c ft_split.c
SRCS += get_next_line.c get_next_line_utils.c ft_printf.c ft_printf_utils.c

BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c
BSRCS += ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

FLAGS = -Wall \
		-Wextra \
		-Werror

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

# $(OBJS): $(SRCS)

bonus: $(BOBJS)

# $(BOBJS): $(BSRCS)

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

rebonus: fclean bonus

%.o: %.c libft.h
#	@echo "$(YELLOW)/(◕◕)\・ﾟ✧ Making libft, Please wait...$(END_COL)"
	@cc $(FLAGS) -c $< -o $@
	ar rcs $(NAME) $@

.PHONY: all clean fclean re rebonus