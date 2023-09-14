# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anacaro3 <anacaro3@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 20:24:48 by gacalaza          #+#    #+#              #
#    Updated: 2023/09/13 23:09:51 by anacaro3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Name of the program =====
NAME =	minishell

# ======= Sources and objs ========
SRCS = minishell.c 

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

FLAGS = -Wall -Wextra -Werror -O3

# =================== Rules ==========================

# # Compiling Mandatory or Bonus Objs
%.o: %.c
	$(CC) $(FLAGS) -I $(INCL_DIR) -c $< -o $@

all: comp_libft $(NAME)

$(OBJS): $(HEADERM)

$(NAME): $(OBJS)
	cc $(FLAGS) $^ $(LIBFT) -o $@

comp_libft:
	@make -C $(LIBFT_DIR) --no-print-directory

re: fclean all

rebonus: fclean bonus

clean:
	@rm -rf $(BOBJS) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

	