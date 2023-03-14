/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:28:06 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "print.h"
#include "parse.h"
#include <stdio.h>
#include <string.h>

/* treating flag(s) if there is/are any */
static void	set_info(int argc, char **argv, int *month, int *show)
{
	int	i;

	*month = 0;
	*show = 0;
	if (argc == 3)
	{
		i = 1;
		while (argv[i])
		{
			if (!*month && atoi(argv[i]))
				*month = set_month(argv[i]);
			if (!strcmp(argv[i], "-s"))
				*show = 1;
			i++;
		}
		if (!*month)
			*month = set_month(argv[1]);
	}
	else if (argc == 2)
	{
		*month = set_month(argv[1]);
		if (!strcmp(argv[1], "-s"))
			*show = 1;
	}
	else
		*month = set_month(argv[1]);
}

static void	init_data(t_data *data)
{
	data->bonus = NULL;
	data->chosen = NULL;
	data->last_month = 0;
	data->month = 0;
	data->show_dates = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	setbuf(stdout, NULL); // setting it for printf does not wait until its buffer reaches '\n'
	parse_api();
	init_data(&data);
	set_info(argc, argv, &data.month, &data.show_dates);
	data.last_month = data.month - 1;
	if (data.month == 1)
		data.last_month = 12;
	set_dates(&data, data.month, data.last_month);
	print_result(&data);
	if (data.bonus)
		free_month(data.bonus);
	if (data.chosen)
		free_month(data.chosen);
	return (0);
}
