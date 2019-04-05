# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 12:06:34 by kaboujna          #+#    #+#              #
#    Updated: 2018/11/27 08:46:05 by kaboujna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fillit

CC		=	gcc

CFLAGS 	=  -Wall -Wextra -Werror

SRCS 	=	fill_it.c \
			map.c \
			parse.c \
			pieces.c \
			set_limit.c \
			solve.c \
			free.c \

LIBFT 	=	libft

OBJS 	= $(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)/libft.a

clean:
	/bin/rm -rf $(OBJS)
	 make -C $(LIBFT) clean

fclean:		clean
	/bin/rm -rf fillit
	 make -C $(LIBFT) fclean

re: fclean all
