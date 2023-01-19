/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 07:37:17 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:28:11 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (*str && *str == c)
		str++;
	if (*str == 0)
		return (0);
	while (*str)
	{
		count++;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
	return (count);
}

static char	*cpy_to_tab(char const *str, size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = malloc((size + 1) * sizeof(char));
	if (!tab)
		return (0);
	while (i < size)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	j;
	size_t	count;

	if (!s)
		return (0);
	count = count_words(s, c);
	tab = malloc((count + 1) * sizeof(char *));
	if (!tab)
		return (0);
	while (*s)
	{
		if (*s && *s != c)
		{
			j = 0;
			while (s[j] && s[j] != c)
				j++;
			*(tab++) = cpy_to_tab(s, j);
			s += j;
		}
		else
			s++;
	}
	*tab = 0;
	return (tab - count);
}
