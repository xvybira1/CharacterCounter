#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_specific_character(const char *str, char character) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == character) {
            count++;
        }
    }
    return count;
}

int count_characters(const char *str) {
    return strlen(str);
}

void print_help() {
    printf("Usage: charcounter <string> or -h or --help\n");
    printf("To count characters, use:\n");
    printf("    charcounter \"Hello, World!\"\n");
    printf("To count specific characters, use:\n");
    printf("    charcounter -c <character> <string>\n");
    printf("    charcounter -character <character> <string>\n");
}

int main(int argc, char *argv[]) {
    
    // User called only the program name without any arguments
    if (argc < 2 || argc > 4) {
        printf("Use charcounter -h for help.\n");
        return 1;
    }
    
    // strcmp returns 0 if the strings are equal
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    }
    
    if (argc == 2) {
        printf("Counted %d characters.\n", count_characters(argv[1]));

    } else if (argc == 4 && ((strcmp(argv[1], "-c") == 0 ) || (strcmp(argv[1], "-character") == 0))) {
        int count = count_specific_character(argv[3], argv[2][0]);
        printf("Counted %d occurrences of '%c'. Total characters: %d\n", count, argv[2][0], count_characters(argv[3]));
    
    } else {
        printf("Invalid arguments. Use charcounter -h for help.\n");
        return 1;
    }

    return 0;
}