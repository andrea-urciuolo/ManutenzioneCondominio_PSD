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