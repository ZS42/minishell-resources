# minishell executable
NAME = minishell

#make directories
INC_DIR = include
SRC_DIR = sources
OBJ_DIR = object
LIBFT_DIR = libft
# libft.a is the library so has .a at end
LIBFT = libft.a
# to find a library on mac use Find / -name libreadline.a
# to get /usr/local/Cellar/readline/8.1/lib/libreadline.a
LIB_READLINE = /usr/local/Cellar/readline/8.1/lib
READLINE_I = /usr/local/Cellar/readline/8.1/include
SRCS = main.c list.c env.c cd.c here_doc.c
#will add all object files into a directory one above
# %o: %c same as .c=.o
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC	= gcc
RM	= rm -rf
#-fsanitize=address can be added to cflags for debugging with -g3
CFLAGS = -g -Wall -Werror -Wextra
#to create all of the .o files from files in SRC_DIR in OBJ_DIR
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(READLINE_I) -I $(INC_DIR) -c $< -o $@

all:	$(NAME)

# goes to file -L
# looks for library -l .All libraries have lib so ft
# this is especially important in linux. Even the order.
#"-c $< -o $@" is equivalent to "$(OBJ_SRC) -o philo"
# -C changes the path
$(NAME): $(OBJS)
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) -L $(LIB_READLINE) $(OBJS) -lreadline -Llibft -lft -o $(NAME)
	@printf "\x1b[31mminishell ready\\x1b[0m\n";

# -o turns object files into executable (coming after it)
#adding an @ before a command stops it from being printed

clean:
	$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "object files removed"
fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "object files and binary removed"

re:	fclean all
	@echo "object files and binary removed and binary remade"

# to remove all recipes that aren't files to avoid relinking
.PHONY:		all clean fclean re