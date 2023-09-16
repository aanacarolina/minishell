# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 20:24:48 by gacalaza          #+#    #+#              #
#    Updated: 2023/09/15 21:43:48 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Name of the program =====
NAME =	minishell

# ======= Sources and objs ========
SRCS = minishell.c prompt.c

OBJS = $(SRCS_MAN:.c=.o)

# ====== Folders and Paths ========
LIBFT_DIR	= ./libft/
INCL_DIR	= ./includes/
MANDATORY	= ./src/
LIBFT		= $(addprefix $(LIBFT_DIR), libft.a)
HEADERM		= $(addprefix $(INCL_DIR), minishell.h)
HEADERB		= $(addprefix $(INCL_DIR), minishell_bonus.h)
SRCS_MAN	= $(addprefix $(MANDATORY), $(SRCS))

# ====== Flags ========

FLAGS = -Wall -Wextra -Werror -g3
LIBS = -lreadline
VALGRIND		=	valgrind \
					--leak-check=full \
					--show-leak-kinds=all \
					--quiet \
					--suppressions=readline.supp \
					--keep-debuginfo=yes \
					--trace-children=yes

# =================== Rules ==========================

# # Compiling Mandatory or Bonus Objs
%.o: %.c
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

all: comp_libft $(NAME)

$(OBJS): $(HEADERM)

$(NAME): $(OBJS)
	cc $(FLAGS) $^ $(LIBFT) $(LIBS) -o $@

comp_libft:
	@make -C $(LIBFT_DIR) --no-print-directory

run:	all
		./$(NAME)

valgrind:	all
			$(VALGRIND) ./$(NAME)

re: fclean all

rebonus: fclean bonus

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

	