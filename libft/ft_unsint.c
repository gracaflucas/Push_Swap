/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:32:12 by lufiguei          #+#    #+#             */
/*   Updated: 2024/05/15 18:32:46 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_ulen(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_unsint(unsigned int n)
{
	int		i;
	int		j;
	char	*str;

	j = ft_ulen(n);
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (0);
	str[j] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--j] = (n % 10) + '0';
		n = n / 10;
	}
	i = ft_putstr(str);
	free(str);
	return (i);
}
