NAME = fractol
FLAGS 			= -Wall -Wextra -Werror -g3
LIBFTFLAGS 		= -L ./libft/ -lft
LIBXFLAGS 		= -lmlx -lXext -lX11 -lm -lz

FILES 	= 	hooks.c \
			julia.c \
			main.c \
			mandelbrot.c \
			utils.c 
			
			
PATH_SRC 		= ./mandatory/src/
SRCS 			= $(addprefix $(PATH_SRC), $(FILES))
OBJS 			= $(FILES:.c=.o)
INCLUDES 		= -I ./mandatory/includes -I ./libft

all:	$(NAME)

$(NAME): libft/libft.a $(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(LIBXFLAGS) $(INCLUDES)

libft/libft.a : 
	@make -C ./libft --no-print-directory

%.o: $(PATH_SRC)%.c
	@cc $(FLAGS) $(INCLUDES) -c $< -o $@


clean:
		rm -rf $(OBJS)
		make -C ./libft clean

fclean:	clean
		rm -rf $(NAME)
		make -C ./libft fclean

re:		fclean all

# -0.4  0.6
# 0.285 0.01
# -0.8 0.156