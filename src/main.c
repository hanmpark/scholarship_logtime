/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:25:52 by hanmpark          #+#    #+#             */
/*   Updated: 2023/08/02 02:31:00 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scholarship_logtime.h"
#include "get_time.h"
#include "print.h"

/* Programs execution order:
* 1. initiatlizes structure
* 2. sets both chosen month's dates and bonus dates
* 3. sets holidays
* 4. calculates the logtimes (bonus, time left, etc.)
* 5. prints out
* 6. frees the structure
*/
int	main(int argc, char **argv)
{
	t_data	data;

	if (!init_data(argc, argv, &data))
		return (1);
	set_dates(&data);
	data.log = get_logs(data);
	print_logtime(data);
	free_structure(data);
	return (0);
}
