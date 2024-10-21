/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:22:54 by lufiguei          #+#    #+#             */
/*   Updated: 2024/05/09 18:22:55 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long nb, const char c)
{
	int		i;
	char	*hex;

	i = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		return (0);
	if (nb < 16)
		return (ft_putchar(hex[nb]));
	else
	{
		i = ft_puthex((nb / 16), c);
		return (i + ft_puthex((nb % 16), c));
	}
	return (i);
}
