/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:04:41 by lufiguei          #+#    #+#             */
/*   Updated: 2024/08/26 20:05:50 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//gets the last node, detach and puts it on top

static void	revrot(t_stack_node **c)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (*c == NULL || (*c)->next == NULL)
		return ;
	first = *c;
	last = last_node(*c);
	if (last->prev != NULL)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*c = last;
}

void	rra(t_stack_node **a)
{
	revrot(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	revrot(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	revrot(a);
	revrot(b);
	ft_printf("rrr\n");
}

void	rrr_to_top(t_stack_node **a,
	t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target && *a != cheap)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}
