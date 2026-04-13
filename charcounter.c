#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_characters(const char *str) {
    return strlen(str);
}

void print_help() {
    printf("Usage: charcounter <string> or -h or --help\n");
    printf("To count characters, use:\n");
    printf("    charcounter \"Hello, World!\"\n");
}

int main(int argc, char *argv[]) {
    
    // User called only the program name without any arguments
    if (argc < 2) {
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
    }

    return 0;
}