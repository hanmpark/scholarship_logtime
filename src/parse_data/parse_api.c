/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_api.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:13:07 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/02 02:30:34 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_next_line.h"
#include "get_time.h"
#include "print.h"

static void	write_holidays_to_fd(char **tab, int year, int i, int fd)
{
	while (tab[i] && atoi(tab[i] + JSON_YEAR) == year)
	{
		write(fd, " ", 1);
		tab[i] += 2;
		tab[i][10] = ' ';
		dprintf(fd, "%s", tab[i]);
		write(fd, "\n", 1);
		tab[i] -= 2;
		i--;
	}
}

static void	sort_holidays(char **tab, int fd)
{
	int	i;

	i = 0;
 	while (tab[i] && atoi(tab[i] + JSON_YEAR) != current_year())
		i++;
	while (tab[i] && atoi(tab[i] + JSON_MONTH) < current_month())
		i++;
	while (tab[i] && atoi(tab[i + 1] + JSON_MONTH) == current_month())
		i++;
	write_holidays_to_fd(tab, current_year(), i, fd);
	while (tab[i] && atoi(tab[i] + JSON_YEAR) != current_year() - 1)
		i++;
	while (tab[i] && atoi(tab[i] + JSON_MONTH) != 12)
		i++;
	write_holidays_to_fd(tab, current_year() - 1, i, fd);
	free_array(tab);
}

static void	sort_dates(char **tab, int fd)
{
	int	i;

	trim_tab(tab, 22);
	i = -1;
	while (tab[++i])
		dprintf(fd, "%s", tab[i]);
	free_array(tab);
}

/* Format json:
* - to be able to easily manipulate the data, splits the json line
* and format it
* - stock the formatted line in a file
*/
void	parse_json(const char *txt_file, int dates)
{
	int		fd;
	char	*str;
	char	**res;

	fd = open(txt_file, O_RDONLY);
	str = get_next_line(fd);
	close(fd);
	res = ft_split(str, ',');
	free(str);
	fd = open(txt_file, O_WRONLY | O_TRUNC);
	if (dates == HOLIDAYS)
		sort_holidays(res, fd);
	else if (dates == DATES)
		sort_dates(res, fd);
	close(fd);
}
