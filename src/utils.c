#include <stdio.h>
#include <string.h>
#include "../include/utils.h"

// Useful for converting dates or time to int for eventual comparison
int StrToInt(char str[]) {
    int i = 0;
    int convertedInt = 0;
    while (str[i] != '\0') {
        // Check if the char is a number
        if (str[i] >= 48 && str[i] <= 57) {
            convertedInt = (convertedInt * 10) + (str[i] - 48);
        }
        i++;
    }

    return convertedInt;
}
void clearBuffer() {
    int c;
    /* Reads and discards characters until it finds a newline or End Of File */
    while ((c = getchar()) != '\n' && c != EOF);
}

void readString(char* buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t length = strlen(buffer);
        /* If the last read character is a newline (\n), replaces it with the null terminator (\0) */
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        } else {
            /* The user typed too many characters: we clear the rest left in the input buffer */
            clearBuffer(); 
        }
    }
}

int readInteger() {
    int value;
    /* scanf returns 1 if it successfully read an integer */
    while (scanf("%d", &value) != 1) {
        printf("Errore: devi inserire un numero. Riprova: ");
        clearBuffer(); /* Discards the invalid input entered by the user */
    }
    clearBuffer(); /* Discards the newline character left in the buffer after the number */
    return value;
}