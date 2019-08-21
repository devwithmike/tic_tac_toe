NAME = tic_tac_toe

SRC_PATH = ./src/

SRCS =	tic_tac_toe.c

FLAGS = -Wall -Werror -Wextra

INC =  -I ./includes/tic_tac_toe.h

SRC = $(addprefix $(SRC_PATH), $(SRCS))

SRCO = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(SRCO)
	@gcc $(FLAGS) -o $(NAME) $(SRC)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m Created.\033[0m"

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -rf $(SRCO)
	@echo "\033[31mObjects Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mRemoved.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re
