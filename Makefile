# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 20:24:48 by gacalaza          #+#    #+#              #
#    Updated: 2023/09/12 20:31:17 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==== Name of the program =====
NAME =	minishell

# ======= Sources and objs ========
SRCS = minishell.c 
SRCS +=

OBJS = $(SRCS:.c=.o)

# ====== Folders and Paths ========
LIBFT_DIR	= ./libs/libft/
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


re: fclean all

rebonus: fclean bonus

clean:
	@rm -rf $(BOBJS) $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
