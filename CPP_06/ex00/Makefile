# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksudyn <ksudyn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/09 18:35:55 by ksudyn            #+#    #+#              #
#    Updated: 2025/10/13 20:15:33 by ksudyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = 
CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
