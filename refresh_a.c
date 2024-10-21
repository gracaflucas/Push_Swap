/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:22:01 by lufiguei          #+#    #+#             */
/*   Updated: 2024/09/05 20:25:35 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		set_index(t_stack_node *c);
static void	set_target_a(t_stack_node *a, t_stack_node *b);
static void	checkcost(t_stack_node *a, t_stack_node *b);
static void	set_cheap(t_stack_node *a);

void	refresh_a(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	checkcost(a, b);
	set_cheap(a);
}

void	set_index(t_stack_node *c)
{
	int	i;
	int	mid;

	i = 0;
	if (c == NULL)
		return ;
	mid = stacklen(c) / 2;
	while (c != NULL)
	{
		c->index = i;
		if (i <= mid)
			c->above_median = 1;
		else
			c->above_median = 0;
		c = c->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_b;
	t_stack_node	*target;
	long			closest;

	while (a != NULL)
	{
		closest = INT_MIN;
		cur_b = b;
		while (cur_b != NULL)
		{
			if (cur_b->data < a->data && cur_b->data > closest)
			{
				closest = cur_b->data;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (closest == INT_MIN)
			a->target = maximum(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	checkcost(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stacklen(a);
	size_b = stacklen(b);
	while (a != NULL)
	{
		a->cost = a->index;
		if (a->above_median == 0)
			a->cost = size_a - (a->index);
		if (a->target->above_median == 1)
			a->cost += a->target->index;
		else
			a->cost += size_b - (a->target->index);
		a = a->next;
	}
}

static void	set_cheap(t_stack_node *a)
{
	long			cheap;
	t_stack_node	*cheap_node;

	if (a == NULL)
		return ;
	cheap = INT_MAX;
	while (a != NULL)
	{
		if (a->cost < cheap)
		{
			cheap = a->cost;
			cheap_node = a;
		}
		a = a->next;
	}
	cheap_node->cheapest = 1;
}
