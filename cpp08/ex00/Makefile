NAME = easyfind
FILES = main.cpp
HEADERS = easyfind.hpp 
FLAGS = c++ -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(FILES) $(HEADERS) 
	$(FLAGS) $(FILES) -o $(NAME)

clean:
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean re
