/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:30:10 by hanmpark          #+#    #+#             */
/*   Updated: 2022/11/26 18:09:11 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int character)
{
	if (character >= 97 && character <= 122)
		character -= 32;
	return (character);
}
