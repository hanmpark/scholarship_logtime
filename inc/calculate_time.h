/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_time.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:04:17 by hanmpark          #+#    #+#             */
/*   Updated: 2023/03/14 01:04:49 by hanmpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATE_TIME_H
# define CALCULATE_TIME_H

int		*ccl_addlog(char **date);
int		*ccl_total_logtime(int *stdlog, int *bnlog);
void	ccl_timeleft(int *ttlog);
int		ccl_hdlog(char **holidays);

#endif