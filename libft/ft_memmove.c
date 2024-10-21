/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:23:06 by lufiguei          #+#    #+#             */
/*   Updated: 2024/04/20 09:07:06 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((unsigned char *)dest < (const unsigned char *)src)
	{
		while (i < n)
		{
			*((unsigned char *)(dest + i))
				= *((const unsigned char *)(src + i));
			i++;
		}
	}
	else if ((unsigned char *)dest > (const unsigned char *)src)
	{
		while (n > 0)
		{
			*((unsigned char *)(dest + n - 1))
				= *((const unsigned char *)(src + n - 1));
			n--;
		}
	}
	return ((unsigned char *)dest);
}
