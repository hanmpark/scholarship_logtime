/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:07:17 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:20:40 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

char	**parse_month(int month, int lastmonth, int fd);
void	set_dates(t_data *data, int month, int last_month);

/* utils */
void	parse_api(void);
void	free_holidays(char **tab);
int		trim_tab(char **tab, int len);
char	**ft_split(const char *s, char c);

#endif