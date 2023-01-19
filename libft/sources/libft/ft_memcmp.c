/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:19:39 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:27:46 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;
	int				i;

	str = (unsigned char *)s1;
	str1 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (str[i] != str1[i])
			return ((str[i] - str1[i]));
		i++;
	}
	return (0);
}
