# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 11:59:19 by hanmpark          #+#    #+#              #
#    Updated: 2023/03/14 00:45:13 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETTINGS
HEADER_PATH = ./inc/
NAME = scholarship_logtime.a

# SOURCES / OBJECTS
SRCS_PATH = ./src/
SRCS_FILES = ${addprefix ${SRCS_PATH}, utils.c}

GNL_PATH = ${SRCS_PATH}gnl/
SRCS_GNL = ${addprefix ${GNL_PATH}, get_next_line.c \
									get_next_line_utils.c}

API_PATH = ${SRCS_PATH}parse_data/
SRCS_API = ${addprefix ${API_PATH}, parse_api.c \
									parse_utils.c \
									parse_month.c}

LOG_PATH = ${SRCS_PATH}logtime/
SRCS_LOG = ${addprefix ${LOG_PATH}, calculate_time.c \
									print_logtime.c \
									check_logtime.c \
									set_holidays.c \
									current_time.c}

SRCS = ${SRCS_FILES} ${SRCS_GNL} ${SRCS_API} ${SRCS_LOG} ${SRCS_PATH}/main.c

OBJS = ${SRCS:.c=.o}

# COMPILER
CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o:%.c ${HEADER_PATH}
	@${CC} ${CFLAGS} -c -I ${HEADER_PATH} $< -o ${<:.c=.o}

# RULES
all: ${NAME}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re