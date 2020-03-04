NAME = scop

GLFW_LOC =	$(shell brew --prefix glfw)
GLFW_INC =	$(GLFW_LOC)/include
GLFW_LINK = -L $(GLFW_LOC)/lib -lglfw

GLEW_LOC =	$(shell brew --prefix glew)
GLEW_INC =	$(GLEW_LOC)/include/
GLEW_LINK = -L $(GLEW_LOC)/lib/ -lGLEW

CC =		clang
CFLAGS =	-Wall -Wextra -Werror

LIBFT =		lib/libft
LIBMATH =	lib/libmath

HEADERS = 	-I includes/ -I $(GLFW_INC) -I $(GLEW_INC)

SRCS =		sources/ft_getenvironment.c \
			sources/ft_parseobject.c \
			sources/ft_mousecallback.c \
			sources/ft_scrollcallback.c \
			sources/ft_processinput.c \
			sources/ft_createtexture.c \
			sources/ft_creatematerial.c \
			sources/ft_setviewmatrix.c \
			sources/main.c \

OBJS =		$(SRCS:.c=.o)

_GREEN =	$ \033[32m
_YELLOW =	$ \033[33m
_RED =		$ \033[31m
_END =		$ \033[0m

all: $(NAME)

%.o: %.c
	@$(CC) -c $(CFLAGS) $(HEADERS) -I. $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(LIBMATH)
	@$(CC) -o $(NAME) $(OBJS) lib/libft/libft.a lib/libmath/libmath.a $(GLFW_LINK) $(GLEW_LINK) -framework OpenGL #-fsanitize=address
	@printf "$(_GREEN)scop compiled\n$(_END)"

clean:
	@$(MAKE) clean -C $(LIBFT)
	@$(MAKE) clean -C $(LIBMATH)
	@/bin/rm -rf $(OBJDIR)
	@printf "libft cleaned\n"
	@printf "libmath cleaned\n"
	@printf "scop cleaned\n"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(MAKE) fclean -C $(LIBMATH)
	@/bin/rm -f $(NAME)
	@printf "scop fcleaned\n"

re: fclean all

.PHONY: all clean fclean re
