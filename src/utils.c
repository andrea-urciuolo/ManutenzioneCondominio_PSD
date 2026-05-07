#include <stdio.h>
#include <stdlib.h>
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
/* Returns 1 if the date is valid, 0 otherwise */
int checkDateValidity(const char* date) {
    // 1. Check for the exact length
    if (strlen(date) != 10) return 0;

    // 2. Format check ('/' characters at positions 4 and 7)
    if (date[4] != '/' || date[7] != '/') return 0;

    // 3. Extract numbers from the string using atoi()
    // atoi automatically stops when it encounters a slash
    int year = atoi(&date[0]);
    int month = atoi(&date[5]);
    int day = atoi(&date[8]);

    // 4. Basic logical checks (year from 2026 onwards)
    if (year < 2026) return 0;
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) return 0;

    // 5. Check for months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return 0;
    }

    // 6. Check for February (including leap year calculation)
    if (month == 2) {
        int isLeap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
        if (isLeap && day > 29) return 0;
        if (!isLeap && day > 28) return 0;
    }

    // If it passes all checks, the date is perfectly valid!
    return 1; 
}