int StrToInt(char str[]);

/* Clears the input buffer (keyboard) */
void clearBuffer();

/* Reads a string with spaces and safely removes the trailing newline */
void readString(char* buffer, int size);

/* Forces the user to input a valid integer number */
int readInteger();