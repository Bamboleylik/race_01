CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -I$(INC_DIR)
SRC_DIR = src
INC_DIR = inc
SRC = $(wildcard $(SRC_DIR)/*.c)

NAME = way_home

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(NAME)

uninstall: clean

reinstall: uninstall all
