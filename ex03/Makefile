CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
RM          = rm -f

NAME        = Intern

INCLUDES = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp \
       RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp

SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
       RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
