CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror

BIN_DIR = bin
BIN = $(BIN_DIR)/estoque

SRCS = \
	main.c \
	estoque.c \
	../../utils/menu/menu.c

.PHONY: all clean

all: $(BIN)

$(BIN): $(SRCS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRCS) -o $(BIN)
	@echo "Executavel gerado em $(BIN)"

clean:
	rm -f $(BIN)
