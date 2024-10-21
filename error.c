/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:48:41 by lufiguei          #+#    #+#             */
/*   Updated: 2024/08/26 19:02:53 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		freestack(t_stack_node	*a);
static void	freesplit(char **split);
static int	isdup(t_stack_node	*a, int num);
void		freestack(t_stack_node	*a);

int	validation(int argc, char **argv, t_stack_node **a)
{
	int		i;
	int		j;
	long	num;
	char	**arguments;

	i = 1;
	while (i < argc)
	{
		arguments = ft_split(argv[i++], ' ');
		if (arguments == NULL)
			return (2);
		j = 0;
		while (arguments[j] != NULL)
		{
			num = ft_atol(arguments[j++]);
			if (num > INT_MAX || num < INT_MIN || isdup(*a, (int)num) == 1)
			{
				freesplit(arguments);
				return (2);
			}
			append_node(a, (int)num);
		}
		freesplit(arguments);
	}
	return (0);
}

static int	isdup(t_stack_node	*a, int num)
{
	t_stack_node	*current;

	current = a;
	while (current != NULL)
	{
		if (current->data == num)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	freesplit(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	freestack(t_stack_node	*a)
{
	t_stack_node	*tmp;

	while (a != NULL)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}
