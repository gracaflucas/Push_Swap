/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:00:47 by lufiguei          #+#    #+#             */
/*   Updated: 2024/08/26 21:02:10 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *nptr)
{
	int			i;
	long int	sign;
	long int	result;

	i = 0;
	result = 0;
	sign = 1;
	if (ft_isdigit(nptr[i]) == 0 && nptr[i] != '-' && nptr[i] != '+')
		return (2147483648);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
		if (ft_isdigit(nptr[i]) == 0)
			return (2147483648);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i++] - '0';
	}
	if (nptr[i] != '\0')
		return (2147483648);
	return (result * sign);
}
