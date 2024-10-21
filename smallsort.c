/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 21:48:26 by lufiguei          #+#    #+#             */
/*   Updated: 2024/09/05 21:48:39 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_stack_node **a)
{
	t_stack_node	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return (1);
	tmp = *a;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sortthree(t_stack_node **a)
{
	t_stack_node	*max;

	max = maximum(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	check_top(t_stack_node	**a)
{
	t_stack_node	*min;

	min = minimum(*a);
	if (min->above_median == 1)
		while (*a != min)
			ra(a);
	else
		while (*a != min)
			rra(a);
}
