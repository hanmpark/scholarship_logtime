/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:41:09 by hanmpark          #+#    #+#             */
/*   Updated: 2023/01/05 11:28:44 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*nstr;

	if (!s)
		return (0);
	nstr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	nstr[i] = 0;
	return (nstr);
}
