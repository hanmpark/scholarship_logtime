# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 16:40:47 by hanmpark          #+#    #+#              #
#    Updated: 2023/01/19 18:34:26 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################### PRESETTINGS ####################
H_DIR			= includes/
LIBFT_DIR		= sources/libft/
FTPRINTF_DIR	= sources/ft_printf/
GNL_DIR			= sources/get_next_line/
NAME			= libft.a

#################### SOURCES AND OBJECTS ####################
SRCS_LIBFT	=	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memset.c \
					ft_strlen.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
					ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
					ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
					ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
					ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
					ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
					ft_lstiter.c ft_lstmap.c

SRCS_FTPRINTF	=	def_flags.c format_hexa.c ft_printf.c print_basic.c \
						print_hexa.c specifier_filter.c treat_charflags.c \
						treat_intflags.c

SRCS_GNL		=	get_next_line_utils.c get_next_line.c

SRCS		=	${addprefix ${LIBFT_DIR}, ${SRCS_LIBFT}} \
				${addprefix ${FTPRINTF_DIR}, ${SRCS_FTPRINTF}} \
				${addprefix ${GNL_DIR}, ${SRCS_GNL}}

OBJS		=	${SRCS:.c=.o}

#################### COMPILER ####################
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

%.o:%.c		${H_FILE}
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

#################### RULES ####################
all:		${NAME}

${NAME}:	${OBJS}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}

clean:
	@rm -f ${OBJS}

fclean:	clean
	@rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus