NAME = Wolf3D

COMPIL = -L/home/sholyu/Bureau/42/07-Wolf3D/minilibx -lm -lmlx -lXext -lX11

COMPILM = gcc -lmlx -framework OpenGL -framework AppKit

SRCS = main.c read.c parse.c ft_usage.c

OBJ = main.o read.o parse.o ft_usage.o

INCLUDES = -I ./

LIB = Libft/libft.a

FLAGS = -Wall -Werror -Wextra

$(NAME) :
	@echo "\033[33;33m===FDF : Compilation for Mac...\033[0m"
	@make -C Libft
	@gcc -c $(SRCS) $(INCLUDES)
	@$(COMPILM) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@mkdir -p TMP
	@mv $(OBJ) TMP

all: $(NAME)

%.o: %.c
	gcc -c $<

linux:
	@echo "\033[33;33m===Wolf : Compilation for Linux...\033[0m"
	@make -C Libft
	@echo "\033[33;33m===Wolf : Starting Compilation...\033[0m"
	@gcc -c $(SRCS) $(INCLUDES)
	@gcc $(OBJ) $(COMPIL) $(LIB) $(INCLUDES) -o $(NAME)
	@echo "\033[33;33m===Wolf : Moving .o files to TMP...\033[0m"
	@mkdir -p TMP
	@mv $(OBJ) TMP

mac:
	@echo "\033[33;33m===FDF : Compilation for Mac...\033[0m"
	@make -C Libft
	@gcc $(FLAGS) -c $(SRCS) $(INCLUDES)
	@$(COMPILM) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@mkdir -p TMP
	@mv $(OBJ) TMP

clean:
	@make clean -C Libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C Libft
	@rm -rf TMP
	@rm -rf $(NAME)

re: fclean all

remac: fclean mac

relinux: fclean linux

.SUFFIXES:

.PHONY: all clean fclean re
