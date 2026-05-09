/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaotome <ksaotome@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:35:51 by tsito             #+#    #+#             */
/*   Updated: 2026/05/09 16:58:19 by tsito            ###   ########.fr       */
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

char				**join_and_split(int ac, char **av);
long				ft_strtol(const char *str);
int					is_valid_int_format(char *str);
int					parse_args(char **args, t_input *input);

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

#endif
