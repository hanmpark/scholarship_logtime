# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parsing.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 19:38:23 by hanmpark          #+#    #+#              #
#    Updated: 2022/12/16 00:12:07 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import re

def parsing(value):
	result = []
	adder = ""
	for i in value:
		if i == " ":
			result.append(adder)
			adder = ""
		else:
			adder += i
	result.append(adder)
	return result

f = open("text_file.txt", "r")
string = parsing(f.read()) [::-1]
f.close()
f = open("text_file.txt", "w")
for i in string:
	i = re.sub('[<>]', '', i)
	i = ''.join(i.partition('.')[0])
	if len(i) == 20:
		i += '"'
	elif len(i) < 20 or len(i) > 21:
		break
	f.write("%s\n" % i)
f.close