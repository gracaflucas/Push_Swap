/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:30:04 by lufiguei          #+#    #+#             */
/*   Updated: 2024/04/20 07:45:05 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if ((unsigned char) c == 0)
		return ((char *)s + i);
	while (i > 0)
	{
		if (s[i - 1] == (unsigned char) c)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (NULL);
}
