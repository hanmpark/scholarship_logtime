/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:44:39 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:23:08 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include <string.h>
#include "parse.h"

void	free_holidays(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;
	int		gap;

	if (!s)
		return (0);
	if (*s == 0 || start > strlen(s))
		return (strdup(""));
	gap = strlen(s) - start;
	while ((size_t)gap > len)
		gap--;
	dest = calloc(gap + 1, sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (i + start < strlen(s) && s[start + i] && i < gap)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}

int	trim_tab(char **tab, int len)
{
	char	*firststr;
	int		i;
	int		k;

	i = 0;
	firststr = ft_substr(tab[i], 1, 22);
	free(tab[i]);
	tab[i] = firststr;
	while (tab[i])
	{
		k = 0;
		while (tab[i][k] && k < len)
			k++;
		tab[i][k++] = '\n';
		tab[i][k] = 0;
		tab[i][0] = ' ';
		tab[i][11] = ' ';
		tab[i][13] = ' ';
		i++;
	}
	return (i);
}

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

char	**ft_split(const char *s, char c)
{
	char	**tab;
	size_t	i;
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
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			*(tab++) = cpy_to_tab(s, i);
			s += i;
		}
		else
			s++;
	}
	*tab = 0;
	return (tab - count);
}
