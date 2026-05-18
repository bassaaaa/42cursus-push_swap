/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:35:51 by tsito             #+#    #+#             */
/*   Updated: 2026/05/16 23:09:35 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef enum e_option
{
	OPTION_INVALID,
	OPTION_ADAPTIVE,
	OPTION_SIMPLE,
	OPTION_MEDIUM,
	OPTION_COMPLEX
}					t_option;

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}					t_operation;

typedef struct s_input
{
	t_option		option;
	int				bench;
	int				*values;
	size_t			size;
}					t_input;

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	char			name;
}					t_stack;

typedef struct s_benchmark
{
	int				counts[OP_COUNT];
}					t_benchmark;

// input
int					is_valid_int_format(char *str);
int					parse_args(char **args, t_input *input);
int					parse_options(char **args, t_input *input, size_t *i);
char				**join_and_split(int ac, char **av);
void				set_index(t_stack *stack);

// init
void				free_stack(t_stack *stk);
int					init_stack(t_stack *a, t_input *input);

// cleanup
void				free_args(char **args);
int					free_input(t_input *input, char **args, int status);
int					free_all(t_stack *a, t_stack *b, t_input *input,
						char **args);

// operations
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

// benchmark
void				print_op(char *name, t_operation op);
void				init_benchmark(void);
int					get_op_count(t_operation op);
int					get_total_ops(void);
void				print_benchmark(t_input *input, double disorder);
void				print_swap_push_counts(void);
void				print_rotate_counts(void);

// utils
long				ft_strtol(const char *str);
int					get_stack_size(t_stack *stack);
int					get_min_pos(t_stack *stack);
void				set_pos(t_stack *stack);
int					get_cost(int pos, int size);
void				push_min_to_b(t_stack *a, t_stack *b);
double				compute_disorder(t_stack *a);

// sort_small
void				select_sort(t_stack *a, t_stack *b);
void				sort_three(t_stack *stack);
void				sort_four(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);

// turk
t_node				*get_cheapest(t_stack *b);
void				move_cheapest(t_stack *a, t_stack *b, t_node *cheapest);
void				rotate_min_to_top(t_stack *a);
void				turk_sort(t_stack *a, t_stack *b);

// chunk_
int					ft_sqrt(int nb);
int					get_chunk_count(int total_size);
int					get_chunk_size(int total_size, int chunk_count);
int					get_chunk_max(int chunk_min, int total, int chunk_size);
void				push_all_chunks_to_b(t_stack *a, t_stack *b,
						int total_size);
void				push_all_chunks_to_a(t_stack *a, t_stack *b,
						int total_size);
void				chunk_sort(t_stack *a, t_stack *b);

#endif
