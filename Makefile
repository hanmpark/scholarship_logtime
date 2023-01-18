# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 11:59:19 by hanmpark          #+#    #+#              #
#    Updated: 2023/01/18 15:57:12 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETTINGS
H_DIR = includes/
NAME = scholarship_logtime.a
SRCS_DIR = sources/

# SOURCES / OBJECTS
SRCS_FILES = get_next_line.c get_next_line_utils.c utils.c calculate_log.c \
				check_logtime.c find_dates.c current_time.c
SRCS = ${addprefix ${SRCS_DIR}, ${SRCS_FILES}} main.c

OBJS = ${SRCS:.c=.o}

# COMPILER
CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o:%.c ${H_DIR}
	@${CC} ${CFLAGS} -c -I ./${H_DIR} $< -o ${<:.c=.o}

# RULES
all: ${NAME}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus