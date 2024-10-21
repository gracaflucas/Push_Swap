/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:22:32 by lufiguei          #+#    #+#             */
/*   Updated: 2024/09/05 21:23:01 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack_node *b, t_stack_node *a);

void	refresh_b(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_a;
	t_stack_node	*target;
	long			closest;

	while (b != NULL)
	{
		closest = INT_MAX;
		cur_a = a;
		while (cur_a != NULL)
		{
			if (cur_a->data > b->data && cur_a->data < closest)
			{
				closest = cur_a->data;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (closest == INT_MAX)
			b->target = minimum(a);
		else
			b->target = target;
		b = b->next;
	}
}

t_stack_node	*get_cheap(t_stack_node **a)
{
	t_stack_node	*cheap;

	cheap = (*a);
	while (cheap != NULL)
	{
		if (cheap->cheapest == 1)
			return (cheap);
		else
			cheap = cheap->next;
	}
	return (NULL);
}
