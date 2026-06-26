#include <stdio.h>

int main()
{
    char input[100];

    while (1) {
        printf("> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        printf("%s", input);
    }

    return 0;
}
