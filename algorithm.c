/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:12:35 by lufiguei          #+#    #+#             */
/*   Updated: 2024/08/30 18:13:37 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_a(t_stack_node **a, t_stack_node **b);
static void	move_to_b(t_stack_node **b, t_stack_node **a);
static void	prep_push(t_stack_node **c, t_stack_node *top, char name);

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	length;

	length = stacklen(*a);
	if (length-- > 3 && issorted(a) == 0)
		pb(a, b);
	if (length-- > 3 && issorted(a) == 0)
		pb(a, b);
	while (length-- > 3 && issorted(a) == 0)
	{
		refresh_a(*a, *b);
		move_to_b(a, b);
	}
	sortthree(a);
	while (*b != NULL)
	{
		refresh_b(*a, *b);
		move_to_a(a, b);
	}
	set_index(*a);
	check_top(a);
}

static void	move_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_push(a, (*b)->target, 'a');
	pa(a, b);
}

static void	move_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap;

	cheap = get_cheap(a);
	if (cheap->above_median == 1 && cheap->target->above_median == 1)
		rr_to_top(a, b, cheap);
	else if (cheap->above_median == 0 && cheap->target->above_median == 0)
		rrr_to_top(a, b, cheap);
	prep_push(a, cheap, 'a');
	prep_push(b, cheap->target, 'b');
	pb(a, b);
}

static void	prep_push(t_stack_node **c, t_stack_node *top, char name)
{
	while (*c != top)
	{
		if (name == 'a')
		{
			if (top->above_median == 1)
				ra(c);
			else
				rra(c);
		}
		else if (name == 'b')
		{
			if (top->above_median == 1)
				rb(c);
			else
				rrb(c);
		}
	}
}
