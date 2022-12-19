/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:13:07 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/19 16:37:53 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/scholarship_logtime.h"

size_t	count_words(char const *str, char c)
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

char	*cpy_to_tab(char const *str, size_t size)
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

int	trim_tab(char **tab)
{
	int		i;
	size_t	len;

	i = 0;
	while (tab[i])
	{
		len = ft_strlen(tab[i]) - 1;
		while (len != 0 && tab[i][len] != '.')
			len--;
		if (len > 0)
			tab[i] = ft_substr(tab[i], len);
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

	fd = open("texts/text_file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Could not open text_file.txt !");
		return (-1);
	}
	str = get_next_line(fd);
	close(fd);
	res = ft_split(str, ' ');
	free(str);
	i = trim_tab(res);
	fd = open("texts/text_file.txt", O_WRONLY | O_TRUNC);
	free(res[i]);
	i--;
	while (i > 0)
	{
		ft_putstr_fd(res[i], fd);
		free(res[i]);
		ft_putstr_fd("\n", fd);
		i--;
	}
	free(res[i]);
	close(fd);
	free(res);
	return (0);
}
