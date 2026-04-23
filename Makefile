# Variabili per il compilatore e i flag
CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

# Trova in automatico tutti i file .c nella cartella src
SRCS = $(wildcard src/*.c)

# Genera i nomi dei file oggetto (.o) corrispondenti
OBJS = $(SRCS:.c=.o)

# Nome dell'eseguibile finale
TARGET = manutenzione

# Regola di default
all: $(TARGET)

# Regola per creare l'eseguibile finale collegando tutti i file oggetto
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regola generica per compilare i singoli file .c in file .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regola per pulire la cartella dai file compilati
clean:
	rm -f $(OBJS) $(TARGET)