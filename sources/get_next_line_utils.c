/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:46:43 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/16 11:17:13 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_freeall(char *buf, char *line, char *stash)
{
	free(buf);
	free(line);
	free(stash);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*tb;
	size_t	len;
	int		i;

	if (count > SIZE_MAX)
		return (NULL);
	len = count * size;
	tb = malloc(len);
	if (!tb)
		return (NULL);
	i = 0;
	while (len)
	{
		tb[i++] = 0;
		len--;
	}
	return (tb);
}

char	*ft_bufferjoin(char *dest, char *src)
{
	char		*joined;
	size_t		len;
	int			i;

	if (!dest)
	{
		dest = ft_calloc(1, sizeof(char));
		if (!dest)
			return (NULL);
	}
	len = ft_strlen(dest) + ft_strlen(src);
	joined = malloc((len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (dest[i])
		*joined++ = dest[i++];
	free(dest);
	i = 0;
	while (src[i])
		*joined++ = src[i++];
	*joined = 0;
	return (joined - len);
}

char	*ft_linetrim(char *str)
{
	char	*tstr;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i + len])
		len++;
	tstr = malloc((len + 1) * sizeof(char));
	if (!tstr)
		return (NULL);
	while (str[i])
		*tstr++ = str[i++];
	*tstr = 0;
	str[i - len] = 0;
	return (tstr - len);
}
