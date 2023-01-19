# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 11:59:19 by hanmpark          #+#    #+#              #
#    Updated: 2023/01/19 18:56:40 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETTINGS
H_DIR = includes/
NAME = scholarship_logtime.a
SRCS_DIR = sources/
LIBFT = libft/

# SOURCES / OBJECTS
SRCS_FILES = check_logtime.c utils.c calculate_log.c find_month.c \
				current_time.c parse_api.c set_holidays.c
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
	@echo "\n\033[3m\033[2;37m\t- Compiling...\033[0m"
	@${MAKE} -C ${LIBFT}
	@cp ${LIBFT}/libft.a ${NAME}
	@ar rcs ${NAME} ${OBJS}
	@echo "\033[3m\033[1;32m   - Compiled -\033[0m"

clean:
	@echo "\n\033[3m\033[2;37m\t- Cleaning objects...\033[0m"
	@${MAKE} clean -C ${LIBFT}
	@rm -f ${OBJS}

fclean: clean
	@echo "\033[3m\033[2;37m\t- Cleaning libraries...\033[0m"
	@rm -f ${NAME}
	@rm -f ${LIBFT}/libft.a
	@echo "\033[3m\033[1;32m   - Cleaned -\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus