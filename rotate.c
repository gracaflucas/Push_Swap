/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soperations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:58:57 by lufiguei          #+#    #+#             */
/*   Updated: 2024/08/26 20:02:40 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// gets the first node, detach and puts it in last

static void	rotate(t_stack_node **c)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (*c == NULL || (*c)->next == NULL)
		return ;
	first = *c;
	last = last_node(*c);
	*c = first->next;
	(*c)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	rr_to_top(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target && *a != cheap)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}
