#include <stdio.h>
#include <string.h>

int main() {
    setbuf(stdout, NULL);

    char input[100];

    while (1) {
        printf("$ ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            continue;
        }

        printf("%s: command not found\n", input);
    }

    return 0;
}
