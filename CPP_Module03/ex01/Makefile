# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgautier <jgautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 17:06:32 by jgautier          #+#    #+#              #
#    Updated: 2023/04/10 17:06:32 by jgautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ScavTrap

SRCS 			= main.cpp \
					ClapTrap.cpp \
					ScavTrap.cpp \

OBJS			= $(SRCS:.cpp=.o)

CC				= c++ -std=c++98
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re