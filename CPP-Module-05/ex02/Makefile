NAME = Bureaucrat

SRCS =	AForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp \
		Bureaucrat.cpp RobotomyRequestForm.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[32m✔ Compilation successful!\033[0m"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)