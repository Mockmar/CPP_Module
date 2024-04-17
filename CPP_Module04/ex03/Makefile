NAME			= Prog

SRCS 			= main.cpp \
					AMateria.cpp \
					Character.cpp \
					Cure.cpp \
					Ice.cpp \
					MateriaSource.cpp \


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