/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:46:59 by lufiguei          #+#    #+#             */
/*   Updated: 2024/09/11 21:47:02 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "libft/libft.h"
# include "push_swap.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	check(t_stack_node **a, t_stack_node **b);

void	execute(t_stack_node **a, t_stack_node **b, char *command);

void	free_all(t_stack_node **a, t_stack_node **b, char *command);

char	*get_next_line(int fd);

#endif
