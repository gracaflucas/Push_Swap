/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:19:15 by lufiguei          #+#    #+#             */
/*   Updated: 2024/04/19 12:21:27 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL && n != 0)
		return (NULL);
	while (i < n)
	{
		(*(unsigned char *)(dest + i)) = (*(const unsigned char *)(src + i));
		i++;
	}
	return (dest);
}
