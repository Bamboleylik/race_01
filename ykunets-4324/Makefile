CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
SRC = src/*.c
INC = -Iinc
BIN = way_home

all:
  $(CC) $(CFLAGS) $(SRC) $(INC) -o $(BIN)

clean:
  rm -f $(BIN)
