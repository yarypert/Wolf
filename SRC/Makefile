NAME = Wolf3D

COMPIL = -L/home/sholyu/Bureau/42/07-Wolf3D/minilibx -lm -lmlx -lXext -lX11

COMPILM = gcc -lmlx -framework OpenGL -framework AppKit

SRCS = main.c read.c parse.c parse2.c parse3.c ft_usage.c draw_image.c hook.c hook2.c hook3.c print_int_tab.c strings.c create_sprites.c adress_sprites.c put_sprites.c destroy_sprites.c wolf.c wolf2.c

OBJ = main.o read.o parse.o parse2.o parse3.o ft_usage.o draw_image.o hook.o hook2.o hook3.o print_int_tab.o strings.o create_sprites.o adress_sprites.o put_sprites.o destroy_sprites.o wolf.o wolf2.o

INCLUDES = -I ./

LIB = Libft/libft.a

FLAGS = -Ofast -Wall -Werror -Wextra

all: $(NAME)

$(NAME) :
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@make -C Libft
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[======                        ]\033[0m"
	@gcc -c $(SRCS) $(INCLUDES)
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[============                  ]\033[0m"
	@$(COMPILM) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[==================            ]\033[0m"
	@mkdir -p TMP
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[========================      ]\033[0m"
	@mv $(OBJ) TMP
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[==============================]\033[0m"
	@echo "\033[38;5;33m===Wolf : Done\033[0m"

generate:
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@make -C Generator
	@make -C Libft
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[======                        ]\033[0m"
	@gcc -c $(SRCS) $(INCLUDES)
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[============                  ]\033[0m"
	@$(COMPILM) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[==================            ]\033[0m"
	@mkdir -p TMP
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[========================      ]\033[0m"
	@mv $(OBJ) TMP
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[==============================]\033[0m"
	@echo "\033[38;5;33m===Wolf : Done\033[0m"


linux:
	@echo "\033[38;5;33m===Wolf : Compilation for Linux...\033[0m"
	@make -C Libft
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Linux...\033[0m"
	@echo "\033[38;5;33m[======                        ]\033[0m"
	@gcc -c $(SRCS) $(INCLUDES)
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Linux...\033[0m"
	@echo "\033[38;5;33m[============                  ]\033[0m"
	@gcc $(OBJ) $(COMPIL) $(LIB) $(INCLUDES) -o $(NAME)
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Linux...\033[0m"
	@echo "\033[38;5;33m[==================            ]\033[0m"
	@mkdir -p TMP
	@mkdir -p TMP
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Linux...\033[0m"
	@echo "\033[38;5;33m[========================      ]\033[0m"
	@mv $(OBJ) TMP
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Linux...\033[0m"
	@echo "\033[38;5;33m[==============================]\033[0m"
	@echo "\033[38;5;33m===Wolf : Done.\033[0m"

mac:
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@make -C Libft
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[======                        ]\033[0m"
	@gcc -c $(SRCS) $(INCLUDES)
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[============                  ]\033[0m"
	@$(COMPILM) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[==================            ]\033[0m"
	@mkdir -p TMP
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[========================      ]\033[0m"
	@mv $(OBJ) TMP
	@clear
	@echo "\033[38;5;33m===Wolf : Compilation for Mac...\033[0m"
	@echo "\033[38;5;33m[==============================]\033[0m"
	@echo "\033[38;5;33m===Wolf : Done\033[0m"

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
