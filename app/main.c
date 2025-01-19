#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    setbuf(stdout, NULL);

    char input[100];

    while (1) {
        printf("$ ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit 0") == 0) {
            exit(0);
        }

        printf("%s: command not found\n", input);
    }

    return 0;
}
