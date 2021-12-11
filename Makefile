NAME = hotrace

SRC = main.c

CXX = cc
CXX_FLAG = -Wall -Wextra -Werror

OBJ = $(SRC:%.c=%.o)

%.o : %.c
	$(CXX) $(CXX_FLAG) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXX_FLAG) $^ -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean
