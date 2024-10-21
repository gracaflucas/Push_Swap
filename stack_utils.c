/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:14:20 by lufiguei          #+#    #+#             */
/*   Updated: 2024/08/30 18:14:47 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **a, int data)
{
	t_stack_node	*new_node;
	t_stack_node	*tmp;

	if (a == NULL)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return ;
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*a == NULL)
		*a = new_node;
	else
	{
		tmp = last_node(*a);
		if (tmp != NULL)
		{
			tmp->next = new_node;
			new_node->prev = tmp;
		}
	}
}

int	stacklen(t_stack_node *a)
{
	int	i;

	if (a == NULL)
		return (0);
	i = 0;
	while (a != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_stack_node	*last_node(t_stack_node *a)
{
	t_stack_node	*last;

	if (a == NULL)
		return (NULL);
	last = a;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_stack_node	*maximum(t_stack_node *a)
{
	long			data_tmp;
	t_stack_node	*maximum;

	data_tmp = INT_MIN;
	maximum = NULL;
	while (a != NULL)
	{
		if (a->data > data_tmp)
		{
			data_tmp = a->data;
			maximum = a;
		}
		a = a->next;
	}
	return (maximum);
}

t_stack_node	*minimum(t_stack_node *a)
{
	long			data_tmp;
	t_stack_node	*minimum;

	data_tmp = INT_MAX;
	minimum = NULL;
	while (a != NULL)
	{
		if (a->data < data_tmp)
		{
			data_tmp = a->data;
			minimum = a;
		}
		a = a->next;
	}
	return (minimum);
}
