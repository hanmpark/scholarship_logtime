/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:44:39 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/02 02:33:32 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_time.h"

#include <string.h>

bool	is_correct_date(char *date, int month, int last_month)
{
	return ((date && find_time(date, TXT_MONTH) == month && find_time(date, TXT_DAY) < 27)
		|| (date && find_time(date, TXT_MONTH) == last_month && find_time(date, TXT_DAY) > 26));
}

int	trim_tab(char **tab, int len)
{
	char	*firststr;
	int		i;
	int		k;

	i = 0;
	firststr = strndup(tab[i] + 1, 23);
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
