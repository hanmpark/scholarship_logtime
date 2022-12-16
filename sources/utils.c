/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:10:24 by hanmpark          #+#    #+#             */
/*   Updated: 2022/12/16 11:24:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
/*\*/
// TELLS WHAT THE CURRENT MONTH IS
char	*month_is(char *src) {
	char	*dest;
	int		i = 0;
	int		j = 5;

	dest = malloc(3 * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < 2)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}

// TELLS WHAT THE CURRENT DAY IS
char	*day_is(char *src) {
	char	*dest;
	int		i = 0;
	int		j = 8;

	dest = malloc(3 * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < 2)
		dest[i++] = src[j++];
	dest[i] = 0;
	return (dest);
}
/**/