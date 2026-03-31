#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char guest[100], search[100];
    int found = 0;

    file = fopen("rk3.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter guest name to search: ");
    scanf(" %[^\n]", search);

    while (fgets(guest, sizeof(guest), file)) {
        guest[strcspn(guest, "\n")] = '\0';
        if (strcmp(guest, search) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found)
        printf("Guest Found\n");
    else
        printf("Guest Not Found\n");

    return 0;
}


