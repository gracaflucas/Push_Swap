/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:19:53 by lufiguei          #+#    #+#             */
/*   Updated: 2024/05/02 18:20:14 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkargs(char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 0)
		return (0);
	if (c == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (c == 'i' || c == 'd')
		i += ft_putnbr(va_arg(ap, int));
	else if (c == 'p')
		i += ft_putptr(va_arg(ap, unsigned long));
	else if (c == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (c == 'u')
		i += ft_unsint(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		i += ft_puthex(va_arg(ap, unsigned int), c);
	else if (c == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	count = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		if (*s == '%')
			count += checkargs(*(++s), ap);
		else
			count += write(1, s, 1);
		s++;
	}
	va_end(ap);
	return (count);
}
