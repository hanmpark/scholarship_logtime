# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 23:47:14 by hanmpark          #+#    #+#              #
#    Updated: 2022/12/16 02:59:25 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
ruby test.rb
python3 parsing.py
gcc main.c sources/get_next_line.c sources/get_next_line_utils.c
./a.out