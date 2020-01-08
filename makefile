NAME = scop

GLFW_LOC = $(shell brew --prefix glfw)
GLFW_INC = $(GLFW_LOC)/include
GLFW_LINK = -L $(GLFW_LOC)/lib -lglfw

GLEW_LOC = $(shell brew --prefix glew)
GLEW_INC = $(GLEW_LOC)/include/
GLEW_LINK = -L $(GLEW_LOC)/lib/ -lGLEW

CC =		clang
CFLAGS =	-Wall -Wextra -Werror

HEADERS = -I includes/ -I $(GLFW_INC) -I $(GLEW_INC)

SRCS = sources/main.c \

OBJS =		$(SRCS:.c=.o)

_GREEN =	$ \033[32m
_YELLOW =	$ \033[33m
_RED =		$ \033[31m
_END =		$ \033[0m

all: $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $(HEADERS) -I. $< -o $@

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(GLFW_LINK) $(GLEW_LINK) -framework OpenGL #-fsanitize=address
	@printf "$(_GREEN)scop compiled\n$(_END)"

clean:
	@/bin/rm -rf $(OBJDIR)
	@printf "scop cleaned\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "scop fcleaned\n"

re: fclean all

.PHONY: all clean fclean re
