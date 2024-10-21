/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:52:57 by lufiguei          #+#    #+#             */
/*   Updated: 2024/08/21 19:53:00 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int					data;
	int					index;
	int					cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target;	
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}			t_stack_node;

int				validation(int argc, char **argv, t_stack_node **a);

int				issorted(t_stack_node **a);

int				stacklen(t_stack_node *a);

void			ra(t_stack_node **a);

void			rb(t_stack_node **b);

void			rr(t_stack_node **a, t_stack_node **b);

void			rr_to_top(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheap);

void			rra(t_stack_node **a);

void			rrb(t_stack_node **b);

void			rrr(t_stack_node **a, t_stack_node **b);

void			rrr_to_top(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheap);

void			sa(t_stack_node **a);

void			sb(t_stack_node **b);

void			ss(t_stack_node **a, t_stack_node **b);

void			pa(t_stack_node **a, t_stack_node **b);

void			pb(t_stack_node **a, t_stack_node **b);

void			append_node(t_stack_node **a, int data);

void			push_swap(t_stack_node **a, t_stack_node **b);

void			sortthree(t_stack_node **a);

void			refresh_a(t_stack_node *a, t_stack_node *b);

void			refresh_b(t_stack_node *a, t_stack_node *b);

void			set_index(t_stack_node *c);

void			check_top(t_stack_node	**a);

void			freestack(t_stack_node	*a);

t_stack_node	*get_cheap(t_stack_node **a);

t_stack_node	*last_node(t_stack_node *a);

t_stack_node	*maximum(t_stack_node *a);

t_stack_node	*minimum(t_stack_node *a);

#endif
