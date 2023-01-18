/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:13:07 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/18 15:31:20 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scholarship_logtime.h"

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

static char	*cpy_to_tab(const char *str, size_t size)
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

static char	**ft_split(const char *s, char c)
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

static int	trim_tab(char **tab)
{
	int		i;
	int		k;

	i = 0;
	while (tab[i])
	{
		k = 0;
		while (tab[i][k] && k < 20)
			k++;
		tab[i][k++] = '"';
		tab[i][k] = 0;
		i++;
	}
	return (i);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*str;
	char	**res;

	fd = open("dates.txt", O_RDONLY);
	str = get_next_line(fd);
	close(fd);
	res = ft_split(str, ' ');
	free(str);
	i = trim_tab(res);
	fd = open("dates.txt", O_WRONLY | O_TRUNC);
	free(res[i]);
	i--;
	while (i > 0)
	{
		ft_putstr_fd(res[i], fd);
		write(fd, "\n", 1);
		free(res[i]);
		i--;
	}
	free(res[i]);
	close(fd);
	free(res);
	return (0);
}
