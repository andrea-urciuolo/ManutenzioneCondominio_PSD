# --- Variabili di compilazione ---
CC = gcc
CFLAGS = -Wall -g
INCLUDES = -Iinclude -Itests

# --- Directory ---
SRC_DIR = src
TEST_DIR = tests/testing_src
OBJ_DIR = obj
BIN_DIR = .

# --- Target finale ---
TARGET = manutenzione.exe

# --- Sorgenti e Oggetti ---
# 1. Recupera la lista di tutti i file .c nelle due cartelle
SRCS_SRC = $(wildcard $(SRC_DIR)/*.c)
SRCS_TEST = $(wildcard $(TEST_DIR)/*.c)

# 2. Genera i nomi dei file .o corrispondenti, mettendoli tutti in OBJ_DIR
# Usiamo notdir per gestire file provenienti da cartelle diverse
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS_SRC) $(SRCS_TEST)))

# --- Regola di default ---
all: $(OBJ_DIR) $(TARGET)

# Crea la cartella obj se non esiste
$(OBJ_DIR):
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Linker
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# --- Regole di Compilazione ---

# Regola per i file che si trovano in SRC_DIR
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Regola per i file che si trovano in TEST_DIR (ora prende tutto, non solo testing.c)
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# --- Pulizia dei file ---
clean:
	@if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	@if exist $(TARGET) del /f /q $(TARGET)

.PHONY: all clean