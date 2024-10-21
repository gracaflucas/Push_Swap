/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:10:24 by lufiguei          #+#    #+#             */
/*   Updated: 2024/08/26 20:10:59 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*move;

	if (*src == NULL)
		return ;
	move = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	move->next = *dest;
	if (*dest != NULL)
		(*dest)->prev = move;
	move->prev = NULL;
	*dest = move;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pb\n");
}
