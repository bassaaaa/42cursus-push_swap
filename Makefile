# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 19:00:55 by tsito             #+#    #+#              #
#    Updated: 2026/05/08 22:48:03 by tsito            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

LIBFTDIR	:= libft
LIBFT		:= $(LIBFTDIR)/libft.a
PRINTF_DIR	:= libftprintf
PRINTF		:= $(PRINTF_DIR)/libftprintf.a
INCLUDES	:= -I. -I$(LIBFTDIR) -I$(PRINTF_DIR)
OUTDIR		:= .out

SRCS		:= \
			chunk_parts.c \
			chunk_sort.c \
			compute_disorder.c \
			ft_sqrt.c \
			ft_strtol.c \
			get_chepest.c \
			get_cost.c \
			get_min_pos.c \
			get_stack_size.c \
			init.c \
			join_and_split.c \
			main.c \
			move_cheapest.c \
			operations_push.c \
			operations_reverse_rotate.c \
			operations_rotate.c \
			operations_swap.c \
			parse.c \
			push_all_chunks_to_a.c \
			push_all_chunks_to_b.c \
			push_min_to_b.c \
			rotate_min.c \
			select_sort.c \
			set_index.c \
			set_pos.c \
			sort_small.c \
			turk_sort.c \
			validate.c
OBJS 		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OUTDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
