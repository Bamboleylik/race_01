CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

BINARY = way_home

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(BINARY)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BINARY): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(BINARY)
	chmod +x $(BINARY)  

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(wildcard $(INC_DIR)/*.h) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)

uninstall: clean
	rm -f $(BINARY)

reinstall: uninstall all

