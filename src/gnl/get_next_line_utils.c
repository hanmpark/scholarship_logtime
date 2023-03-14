/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:20:26 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:10:38 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_next_line.h"

void	ft_freeall(char *buf, char *line, char *stash)
{
	free(buf);
	free(line);
	free(stash);
}

char	*ft_bufferjoin(char *dest, char *src)
{
	char		*joined;
	size_t		len;
	int			i;

	if (!dest)
	{
		dest = calloc(1, sizeof(char));
		if (!dest)
			return (0);
	}
	len = strlen(dest) + strlen(src);
	joined = malloc((len + 1) * sizeof(char));
	if (!joined)
		return (0);
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
		return (0);
	while (str[i])
		*tstr++ = str[i++];
	*tstr = 0;
	str[i - len] = 0;
	return (tstr - len);
}
