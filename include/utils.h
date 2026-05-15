#ifndef UTILS_H
#define UTILS_H

/*
 * Function: StrToInt
 * ----------------------
 * Extracts digits from a string and converts them into an integer
 *
 * Parameters:
 *   str: The string containing the characters to be converted
 *
 * Pre-conditions:
 *   str must be a null-terminated character array
 *
 * Post-conditions:
 *   Returns the int value formed by all the digits found in the string,
 *   ignoring any non-numeric characters.
 *
 * Returns:
 *   The converted int. For example, "2026/05/15" becomes 20260515.
 */
int StrToInt(char str[]);

/*
 * Function: clearBuffer
 * ----------------------
 * Clears the standard input buffer
 *
 * Parameters:
 *   None (void)
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   All characters remaining in the input buffer, up to and including
 *   the next newline ('\n') or the End Of File (EOF), are read and discarded.
 *
 * Side-effect:
 *   Prevents subsequent input functions (like fgets, scanf or getchar) from
 *   reading garbage or leftover characters from previous inputs.
 *
 * Returns:
 *   void
 */
void clearBuffer();

/*
 * Function: readString
 * ----------------------
 * Reads a string from standard input safely
 *
 * Parameters:
 *   buffer: The character array where the string will be stored
 *   size: The maximum number of characters to read (including the null terminator)
 *
 * Pre-conditions:
 *   buffer must be pre-allocated and have a capacity of at least 'size'
 *
 * Post-conditions:
 *   Reads up to 'size - 1' characters. If a newline ('\n') is read, it is
 *   replaced with a null terminator ('\0'). If the input exceeds 'size',
 *   the remaining characters in the buffer are cleared to prevent
 *   polluting subsequent reads.
 *
 * Side-effect:
 *   Modifies the content of 'buffer'.
 *
 * Returns:
 *   void
 */
void readString(char* buffer, int size);

/*
 * Function: readInteger
 * ----------------------
 * Reads an integer from standard input with basic validation
 *
 * Parameters:
 *   None (void)
 *
 * Pre-conditions:
 *   None
 *
 * Post-conditions:
 *   Returns the integer entered by the user. If the input is not a valid
 *   integer, it prompts the user to try again until a valid number is provided.
 *
 * Side-effect:
 *   Always clears the input buffer after a successful or failed read to
 *   remove the newline character ('\n') or any invalid trailing characters.
 *   Outputs an error message to standard output in case of invalid input.
 *
 * Returns:
 *   The valid integer value entered by the user
 */
int readInteger();

/*
 * Function: checkDateValidity
 * ----------------------
 * Validates a date string in the format "YYYY/MM/DD"
 *
 * Parameters:
 *   date: A constant string representing the date to be checked
 *
 * Pre-conditions:
 *   date must be a null-terminated string
 *
 * Post-conditions:
 *   Returns 1 if the date is logically and syntactically valid; 0 otherwise.
 *
 * Returns:
 *   An int (1 for valid date, 0 for invalid)
 */
int checkDateValidity(const char* date);

/*
 * Function: checkTimeValidity
 * ----------------------
 * Validates a time string in the 24-hour format "HH:MM"
 *
 * Parameters:
 *   time: A constant string representing the time to be checked
 *
 * Pre-conditions:
 *   time must be a null-terminated string
 *
 * Post-conditions:
 *   Returns 1 if the time is logically and syntactically valid; 0 otherwise.
 *
 * Returns:
 *   An integer (1 for valid time, 0 for invalid)
 */
int checkTimeValidity(const char* time);

#endif
