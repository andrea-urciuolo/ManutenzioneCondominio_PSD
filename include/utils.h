#ifndef UTILS_H
#define UTILS_H

int StrToInt(char str[]);

/* Clears the input buffer (keyboard) */
void clearBuffer();

/* Reads a string with spaces and safely removes the trailing newline */
void readString(char* buffer, int size);

/* Forces the user to input a valid integer number */
int readInteger();

/* Check if a string is a valid date (YYYY/MM/DD format) and >= 2026 */
int checkDateValidity(const char* date);

/* Check if a string is a valid time (HH:MM format) */
int checkTimeValidity(const char* time);
#endif
