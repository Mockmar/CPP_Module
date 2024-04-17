NAME			= PmergeMe

SRCS 			= main.cpp \
					PmergeMe.cpp \

OBJS			= $(SRCS:.cpp=.o)

CC				= c++ -std=c++98
RM				= rm -f
CXXFLAGS			= -Wall -Wextra -Werror -g

all:			$(NAME)

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re