# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 11:29:51 by hbruvry           #+#    #+#              #
#    Updated: 2018/10/15 09:26:39 by hbruvry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		ft_vec3set.c \
			ft_vec3cpy.c \
			ft_vec3add.c \
			ft_vec3sub.c \
			ft_vec3magnitude.c \
			ft_vec3norm.c \
			ft_vec3cross.c \
			ft_vec3dot.c \
			ft_vec3scalar.c \
			ft_vec3print.c \
			ft_mat4set.c \
			ft_mat4cpy.c \
			ft_mat4add.c \
			ft_mat4sub.c \
			ft_mat4mul.c \
			ft_mat4scalar.c \
			ft_mat4scale.c \
			ft_mat4rotate.c \
			ft_mat4translate.c \
			ft_mat4transform.c \
			ft_mat4transpose.c \
			ft_mat4print.c \
			ft_vec3appmat4.c \

OBJS =		$(SRCS:.c=.o)

NAME =		libmath.a

CC =		clang

CFLAGS =	-Wall -Wextra -Werror

_GREEN =	$ \033[32m
_YELLOW =	$ \033[33m
_RED =		$ \033[31m
_END =		$ \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(CFLAGS) -I. -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "$(_GREEN)libmath compiled\n$(_END)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@printf "libmath fcleaned\n"

re: fclean all

.PHONY : clean fclean all re