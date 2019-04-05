# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 12:06:34 by kaboujna          #+#    #+#              #
#    Updated: 2018/11/27 08:46:19 by kaboujna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS =  -Wall -Wextra -Werror

SRCS = *.c
all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I .
	ar rc $(NAME) $(SRCS:.c=.o)
	ranlib $(NAME)

clean:
	rm -rf $(SRCS:.c=.o)

fclean: clean
	rm -rf $(NAME)

re: fclean all
