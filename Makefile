NAME = ft_containers

SRC = vector_test.cpp

SRC_MAP = tests/

SRCS = $(addprefix $(SRC_MAP), $(SRC))

INCLUDE = -I srcs

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): vector
	@echo "Please choose test!"

vector: real_vector
	clang++ -o vector_test tests/vector_test.cpp -Wall -Werror -Wextra -std=c++98 -pedantic -g -fsanitize=address
	./real_vector_test
	./vector_test

real_vector:
	clang++ -o real_vector_test tests/real_vector_test.cpp -Wall -Werror -Wextra -std=c++98 -pedantic -g -fsanitize=address

#$(NAME): $(OBJS)
#	clang++ -o $@ $^ -Wall -Werror -Wextra -std=c++98 -pedantic

%.o: %.cpp
	clang++ -o $@ -c $< $(INCLUDE) -Wall -Werror -Wextra -std=c++98 -pedantic

clean:
	-rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	-rm -f $(OBJS)
	-rm -f vector_test
	-rm -f real_vector_test

re: fclean all

.PHONY: ft_containers vector real_vector clean fclean all re