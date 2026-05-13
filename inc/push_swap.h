/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:35:51 by tsito             #+#    #+#             */
/*   Updated: 2026/05/13 19:11:26 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libftprintf/ft_printf.h"

typedef enum e_option
{
	OPTION_INVALID,
	OPTION_ADAPTIVE,
	OPTION_SIMPLE,
	OPTION_MEDIUM,
	OPTION_COMPLEX
}					t_option;

typedef struct s_input
{
	t_option		option;
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

// input
int					is_valid_int_format(char *str);
int					parse_args(char **args, t_input *input);
char				**join_and_split(int ac, char **av);
void				set_index(t_stack *stack);

// init
void				free_stack(t_stack *stk);
int					init_stack(t_stack *a, t_input *input);

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

// utils
long				ft_strtol(const char *str);
int					get_stack_size(t_stack *stack);
int					get_min_pos(t_stack *stack);
void				set_pos(t_stack *stack);
int					get_cost(int pos, int size);

// sort_small
void				sort_three(t_stack *stack);
void				sort_four(t_stack *a, t_stack *b);
void				sort_five(t_stack *a, t_stack *b);

// turk
t_node				*get_cheapest(t_stack *b);
void				move_cheapest(t_stack *a, t_stack *b, t_node *cheapest);
void				rotate_min_to_top(t_stack *a);
void				turk_sort(t_stack *a, t_stack *b);

#endif
