/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:45:47 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:28:50 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (i < len && (char)haystack[i])
	{
		if (!(ft_strncmp((char *)haystack + i, (char *)needle,
					ft_strlen(needle))))
		{
			if (ft_strlen(needle) + i > len)
				return (NULL);
			return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
