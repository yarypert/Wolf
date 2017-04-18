NAME = Wolf3D

COMPIL = -L/home/sholyu/Bureau/42/07-Wolf3D/minilibx -lm -lmlx -lXext -lX11

COMPILM = gcc -lmlx -framework OpenGL -framework AppKit

SRCS = main.c read.c parse.c parse2.c ft_usage.c

OBJ = main.o read.o parse.o parse2.o ft_usage.o

INCLUDES = -I ./

LIB = Libft/libft.a

FLAGS = -Ofast -Wall -Werror -Wextra

all: $(NAME)

$(NAME) :
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@make -C Libft
	@echo "\033[38;5;33m===Wolf : Starting Compilation...\033[0m"
	@echo "\033[38;5;33m===Wolf : Recompiling Libft...\033[0m"
	@gcc -c $(SRCS) $(INCLUDES)
	@$(COMPILM) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@echo "\033[38;5;33m===Wolf : Moving .o files to TMP...\033[0m"
	@mkdir -p TMP
	@mv $(OBJ) TMP
	@echo "\033[38;5;33m===Wolf : Done\033[0m"

linux:
	@echo "\033[38;5;33m===Wolf : Compilation for Linux...\033[0m"
	@make -C Libft
	@echo "\033[38;5;33m===Wolf : Starting Compilation...\033[0m"
	@echo "\033[38;5;33m===Wolf : Recompiling Libft...\033[0m"
	@gcc -c $(SRCS) $(INCLUDES)
	@gcc $(OBJ) $(COMPIL) $(LIB) $(INCLUDES) -o $(NAME)
	@echo "\033[38;5;33m===Wolf : Moving .o files to TMP...\033[0m"
	@mkdir -p TMP
	@mv $(OBJ) TMP
	@echo "\033[38;5;33m===Wolf : Done.\033[0m"

mac:
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@make -C Libft
	@echo "\033[38;5;33m===Wolf : Starting Compilation...\033[0m"
	@echo "\033[38;5;33m===Wolf : Recompiling Libft...\033[0m"
	@gcc -c $(SRCS) $(INCLUDES)
	@gcc $(FLAGS) -c $(SRCS) $(INCLUDES)
	@$(COMPILM) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@echo "\033[38;5;33m===Wolf : Moving .o files to TMP...\033[0m"
	@mkdir -p TMP
	@mv $(OBJ) TMP
	@echo "\033[38;5;33m===Wolf : Done.\033[0m"

clean:
	@make clean -C Libft
	@echo "\033[38;5;1m===Wolf : Deleting .o Files...\033[0m"
	@rm -rf TMP

fclean: clean
	@make fclean -C Libft
	@echo "\033[38;5;1m===Wolf : Deleting Wolf3D executable...\033[0m"
	@rm -rf $(NAME)
	@echo "\033[38;5;1m===Wolf : Deleted.\033[0m"

re: fclean all

remac: fclean mac

relinux: fclean linux

.SUFFIXES:

.PHONY: all clean fclean re
