#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    setbuf(stdout, NULL);

    while (1) {
        printf("$ ");
        fflush(stdout);
        char input[100];

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\r\n")] = 0;

        if (strcmp(input, "exit 0") == 0) {
            return 0;
        }

        if (strncmp(input, "echo", strlen("echo")) == 0) {
            printf("%s\n", input + 5);
            continue;
        }

        printf("%s: command not found\n", input);
    }

    return 0;
}
