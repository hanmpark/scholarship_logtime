# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 11:59:19 by hanmpark          #+#    #+#              #
#    Updated: 2023/08/03 20:45:08 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              SOURCES / OBJECTS                               #
# **************************************************************************** #
SRCS_PATH = ./src/

SRCS_SRCS = ${addprefix ${SRCS_PATH}, main.c \
										init_data.c \
										parse_month.c}

GNL_PATH = ${SRCS_PATH}gnl/
SRCS_GNL = ${addprefix ${GNL_PATH}, get_next_line.c \
									get_next_line_utils.c}

CALCULATE_PATH = ${SRCS_PATH}calculate/
SRCS_CALCULATE = ${addprefix ${CALCULATE_PATH}, calculate_logs.c \
												get_logs.c \
												current_time.c \
												calculate_average.c}

PRINT_PATH = ${SRCS_PATH}print/
SRCS_PRINT = ${addprefix ${PRINT_PATH}, print_logtime.c \
										check_logtime.c \
										progress_bar.c}

SRCS = ${SRCS_GNL} ${SRCS_API} ${SRCS_CALCULATE} ${SRCS_PRINT} ${SRCS_LOG} ${SRCS_SRCS}

OBJS = ${SRCS:.c=.o}

# *************************************************************************** #
#                                  COMPILER                                   #
# *************************************************************************** #
CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
	CFLAGS += -fsanitize=address -g
endif

HEADER_PATH = ./inc/

%.o:%.c ${HEADER_PATH}
	@${CC} ${CFLAGS} -c -I ${HEADER_PATH} $< -o ${<:.c=.o}

# *************************************************************************** #
#                                    RULES                                    #
# *************************************************************************** #
NAME = calculator

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

debug:
	@${MAKE} DEBUG=1

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re debug