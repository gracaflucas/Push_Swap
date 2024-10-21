/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 07:20:32 by lufiguei          #+#    #+#             */
/*   Updated: 2024/04/23 07:26:40 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long long int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	reverse(char *c, int size)
{
	char	tmp;
	int		start;
	int		end;

	start = 0;
	if (c[0] == '-')
		start = 1;
	end = size - 1;
	while (start < end)
	{
		tmp = c[start];
		c[start] = c[end];
		c[end] = tmp;
		start++;
		end--;
	}
}

char	*ft_itoa(int n)
{
	char			*buffer;
	long int		digits;
	int				i;
	long long int	num;

	num = (long long int)n;
	digits = count_digits(num);
	buffer = (char *)malloc(sizeof(char) * (digits + 1));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	buffer[digits] = '\0';
	if (num < 0)
	{
		buffer[i++] = '-';
		num = -num;
	}
	while (digits > i)
	{
		buffer[i++] = num % 10 + '0';
		num = num / 10;
	}
	reverse(buffer, i);
	return (buffer);
}
