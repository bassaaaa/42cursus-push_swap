# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 19:00:55 by tsito             #+#    #+#              #
#    Updated: 2026/05/18 18:08:00 by tsito            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

LIBFTDIR	:= libft
LIBFT		:= $(LIBFTDIR)/libft.a
INCLUDES	:= -I. -I$(LIBFTDIR)
OUTDIR		:= .out

SRCS		:= \
			benchmark.c \
			cleanup.c \
			chunk_parts.c \
			chunk_sort.c \
			compute_disorder.c \
			ft_sqrt.c \
			ft_strtol.c \
			get_min_pos.c \
			get_stack_size.c \
			init.c \
			join_and_split.c \
			main.c \
			operations_push.c \
			operations_reverse_rotate.c \
			operations_rotate.c \
			operations_swap.c \
			parse_args.c \
			parse_options.c \
			print_benchmark.c \
			print_benchmark_counts.c \
			push_all_chunks_to_a.c \
			push_all_chunks_to_b.c \
			radix_sort.c \
			rotate_min.c \
			select_sort.c \
			set_index.c \
			validate.c
OBJS 		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OUTDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
