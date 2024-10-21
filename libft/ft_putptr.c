/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:22:48 by lufiguei          #+#    #+#             */
/*   Updated: 2024/05/09 18:22:49 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(unsigned long nb)
{
	int	i;

	i = 0;
	if (!nb)
		return (write(1, "(nil)", 5));
	i += ft_putstr("0x");
	i += ft_puthex(nb, 'x');
	return (i);
}
