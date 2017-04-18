NAME = MapGenerator

SRCS = main.c mapgen.c place.c usage.c

OBJ = main.o mapgen.o place.o usage.o

INC = -I ./

LIB = ../Libft/libft.a

FLAGS = -O3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@echo "\033[038;5;11m===Generator : Starting Compilation... \033[0m"
	@echo "\033[038;5;11m===Generator : Recompiling Libft \033[0m"
	@make -C ../Libft
	@echo "\033[038;5;11m===Generator : Creating .o... \033[0m"
	@gcc -c $(SRCS) $(INC)
	@gcc $(OBJ) $(LIB) $(INC) -o $(NAME)
	@echo "\033[038;5;11m===Generator : Moving .o files to TMP... \033[0m"
	@mkdir -p TMP
	@mv $(OBJ) TMP
	@echo "\033[038;5;11m===Generator : Done \033[0m"

clean:
	@make clean -C ../Libft
	@rm -rf TMP
	@echo "\033[038;5;1m===Generator : Deleting .o files... \033[0m"
	@echo "\033[038;5;1m===Generator : Deleting map...\033[0m"
	@rm -rf Map.wolf

fclean: clean
	@make fclean -C ../Libft
	@echo "\033[038;5;1m===Generator : Deleting MapGenerator executable...\033[0m"
	@rm -rf $(NAME)
	@echo "\033[038;5;1m===Generator : Deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re
