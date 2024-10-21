/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:07:12 by lufiguei          #+#    #+#             */
/*   Updated: 2024/04/22 07:56:23 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char const c, char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1)
	{
		if (isset(((char)*s1), set) == 1)
			s1++;
		else
			break ;
	}
	size = ft_strlen(s1);
	while (size > 0)
	{
		if (isset(s1[size - 1], set) == 1)
			size--;
		else
			break ;
	}
	str = (char *)malloc(size * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (char *)s1, size + 1);
	return (str);
}
