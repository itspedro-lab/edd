CC ?= cc
CFLAGS ?= -Wall -Wextra -Werror

BIN_DIR = bin
MENU_BIN = $(BIN_DIR)/a1_menu

MENU_SRCS = \
	main.c \
	menu/menu.c \
	professor/main.c \
	produto/main.c \
	livro/main.c \
	cliente/main.c \
	func/main.c \
	carro/main.c \
	conta/main.c \
	endereco/main.c \
	filme/main.c \
	aluno-ex/main.c

.PHONY: menu clean

menu:
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -DA1_MENU_BUILD $(MENU_SRCS) -o $(MENU_BIN)
	@echo "Executavel gerado em $(MENU_BIN)"

clean:
	rm -f $(MENU_BIN)
