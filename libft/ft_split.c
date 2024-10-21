/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:08:00 by lufiguei          #+#    #+#             */
/*   Updated: 2024/04/22 08:16:51 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	checksplits(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = 0;
		else if (s[i] != c && j == 0)
		{
			count++;
			j = 1;
		}
		i++;
	}
	return (count);
}

static int	checksize(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*allocstr(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	size = checksize(s, c);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**spliter(char **split, const char *s, size_t num_splits, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	while (num_splits > i)
	{
		while (s[j] == c)
			j++;
		size = checksize(s + j, c);
		split[i] = allocstr(s + j, c);
		if (split[i] == NULL)
		{
			i = 0;
			while (split[i])
				free(split[i++]);
			free(split);
			return (NULL);
		}
		j += size;
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_splits;
	char	**split;

	if (s == NULL)
		return (NULL);
	num_splits = checksplits(s, c);
	split = (char **)malloc((num_splits + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	split = spliter(split, s, num_splits, c);
	if (split == NULL)
		return (NULL);
	split[num_splits] = NULL;
	return (split);
}
