NAME = MapGenerator

SRCS = main.c mapgen.c place.c usage.c

OBJ = main.o mapgen.o place.o usage.o

INC = -I ./

LIB = ../Libft/libft.a

FLAGS = -O3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@clear
	@echo "\033[038;5;28m===Generator : Compilation... \033[0m"
	@make -C ../Libft
	@clear
	@echo "\033[38;5;28m===Generator : Compilation...\033[0m"
	@echo "\033[38;5;28m[======                        ]\033[0m"
	@gcc -c $(SRCS) $(INC)
	@clear
	@echo "\033[38;5;28m===Generator : Compilation...\033[0m"
	@echo "\033[38;5;28m[============                  ]\033[0m"
	@gcc $(OBJ) $(LIB) $(INC) -o $(NAME)
	@mkdir -p TMP
	@clear
	@echo "\033[38;5;28m===Generator : Compilation...\033[0m"
	@echo "\033[38;5;28m[==================            ]\033[0m"
	@clear
	@echo "\033[38;5;28m===Generator : Compilation...\033[0m"
	@echo "\033[38;5;28m[========================      ]\033[0m"
	@mv $(OBJ) TMP
	@clear
	@echo "\033[38;5;28m===Generator : Compilation...\033[0m"
	@echo "\033[38;5;28m[==============================]\033[0m"
	@echo "\033[038;5;28m===Generator : Done \033[0m"

clean:
	@make clean -C ../Libft
	@echo "\033[038;5;1m===Generator : Deleting .o files... \033[0m"
	@echo "\033[038;5;1m===Generator : Deleting map...\033[0m"
	@rm -rf TMP
	@rm -rf Map.wolf

fclean: clean
	@make fclean -C ../Libft
	@echo "\033[038;5;1m===Generator : Deleting MapGenerator executable...\033[0m"
	@rm -rf $(NAME)
	@echo "\033[038;5;1m===Generator : Deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re
