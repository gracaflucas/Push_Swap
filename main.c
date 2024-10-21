/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:52:01 by lufiguei          #+#    #+#             */
/*   Updated: 2024/08/21 19:52:46 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	b = NULL;
	a = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	if (validation(argc, argv, &a) == 2)
	{
		freestack(a);
		return (ft_printf("Error\n"));
	}
	if (issorted(&a) == 0)
	{
		if (stacklen(a) == 2)
			sa(&a);
		else if (stacklen(a) == 3)
			sortthree(&a);
		else
			push_swap(&a, &b);
	}
	freestack(a);
	return (0);
}
