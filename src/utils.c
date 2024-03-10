/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:54:24 by hanmpark          #+#    #+#             */
/*   Updated: 2024/03/10 22:00:29 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"

#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p_o;
	char	*p_n;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	p_o = (char *)malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	if (p_o == NULL)
		return (NULL);
	p_n = p_o;
	while (*s1)
		*p_n++ = *s1++;
	while (*s2)
		*p_n++ = *s2++;
	*p_n = '\0';
	return (p_o);
}

char	*ft_strdup(const char *s)
{
	char	*s_o;
	char	*s_n;

	s_o = malloc((strlen(s) + 1) * sizeof(char));
	if (s_o == NULL)
		return (NULL);
	s_n = s_o;
	while (*s)
	{
		*s_n = *s;
		s_n++;
		s++;
	}
	*s_n = '\0';
	return (s_o);
}
