# --- Variabili di compilazione ---
CC = gcc
CFLAGS = -Wall -g
# Include sia la cartella include/ che la cartella tests/ per gli header
INCLUDES = -Iinclude -Itests

# --- Directory ---
SRC_DIR = src
TEST_DIR = tests
OBJ_DIR = obj
BIN_DIR = .

# --- Target finale ---
TARGET = manutenzione.exe

# --- Sorgenti e Oggetti ---
# Prende tutti i .c in src e aggiunge specificamente testing.c
SRCS = $(wildcard $(SRC_DIR)/*.c) $(TEST_DIR)/testing.c

# Trasforma i percorsi dei file .c in percorsi .o dentro la cartella obj
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c)) \
       $(OBJ_DIR)/testing.o

# --- Regola di default ---
all: $(OBJ_DIR) $(TARGET)

# Crea la cartella obj se non esiste (Sintassi Windows)
$(OBJ_DIR):
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Linker: Crea l'eseguibile unendo tutti i file .o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilazione dei file .c in src/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilazione specifica per testing.c in tests/
$(OBJ_DIR)/testing.o: $(TEST_DIR)/testing.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# --- Pulizia dei file ---
clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(TARGET) del /f /q $(TARGET)

.PHONY: all clean