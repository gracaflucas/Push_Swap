/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:39:48 by lufiguei          #+#    #+#             */
/*   Updated: 2024/09/11 21:40:05 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	check(t_stack_node **a, t_stack_node **b);
void	execute(t_stack_node **a, t_stack_node **b, char *command);
void	free_all(t_stack_node **a, t_stack_node **b, char *command);

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*command;

	a = NULL;
	b = NULL;
	command = NULL;
	if (validation(argc, argv, &a) == 2)
	{
		freestack(a);
		return (ft_printf("Error\n"));
	}
	while (1)
	{
		command = get_next_line(0);
		if (command == NULL)
		{
			free (command);
			break ;
		}
		execute(&a, &b, command);
		free (command);
	}
	check(&a, &b);
}

void	check(t_stack_node **a, t_stack_node **b)
{
	if (issorted(a) == 1 && *b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	freestack(*a);
	freestack(*b);
}

void	execute(t_stack_node **a, t_stack_node **b, char *command)
{
	if (ft_strncmp(command, "pa\n", 4) == 0)
		pa(a, b);
	else if (ft_strncmp(command, "pb\n", 4) == 0)
		pb(a, b);
	else if (ft_strncmp(command, "sa\n", 4) == 0)
		sa(a);
	else if (ft_strncmp(command, "sb\n", 4) == 0)
		sb(b);
	else if (ft_strncmp(command, "ss\n", 4) == 0)
		ss(a, b);
	else if (ft_strncmp(command, "ra\n", 4) == 0)
		ra(a);
	else if (ft_strncmp(command, "rb\n", 4) == 0)
		rb(b);
	else if (ft_strncmp(command, "rr\n", 4) == 0)
		rr(a, b);
	else if (ft_strncmp(command, "rra\n", 5) == 0)
		rra(a);
	else if (ft_strncmp(command, "rrb\n", 5) == 0)
		rrb(b);
	else if (ft_strncmp(command, "rrr\n", 5) == 0)
		rrr(a, b);
	else
		free_all(a, b, command);
}

void	free_all(t_stack_node **a, t_stack_node **b, char *command)
{
	freestack(*a);
	freestack(*b);
	free(command);
	ft_printf("Error\n");
	exit(1);
}
