#include <stdio.h>
#include <stdlib.h>
#include <tokenizer.h>

int main()
{
    char input[256];
    int choice;

    while (1) {
        printf("\n===== TOKENZIER =====\n");
        printf("1. Test space_char()\n");
        printf("2. Test non_space_char()\n");
        printf("3. Test token_start()\n");
        printf("4. Test token_terminator()\n");
        printf("5. Test count_tokens()\n");
        printf("6. Test tokenize()\n");
        printf("7. Test copy_str()\n");
        printf("0. Quit\n");
        printf("> ");

        scanf("%d", &choice);
        getchar();      // remove newline after scanf

        switch (choice) {

        case 1:
            printf("Enter one character: ");
            scanf("%c", &input[0]);
            getchar();

            printf("space_char('%c') = %d\n",
                   input[0], space_char(input[0]));
            break;

        case 2:
            printf("Enter one character: ");
            scanf("%c", &input[0]);
            getchar();

            printf("non_space_char('%c') = %d\n",
                   input[0], non_space_char(input[0]));
            break;

        case 3: {
            printf("Enter a string:\n> ");
            fgets(input, sizeof(input), stdin);

            // Remove newline
            int i = 0;
            while (input[i] != '\0') {
                if (input[i] == '\n') {
                    input[i] = '\0';
                    break;
                }
                i++;
            }

            char *start = token_start(input);

            if (start)
                printf("First token starts with: %c\n", *start);
            else
                printf("No tokens found.\n");

            break;
        }

        case 4: {
            printf("Enter a string:\n> ");
            fgets(input, sizeof(input), stdin);

            // Remove newline
            int i = 0;
            while (input[i] != '\0') {
                if (input[i] == '\n') {
                    input[i] = '\0';
                    break;
                }
                i++;
            }

            char *start = token_start(input);

            if (start) {
                char *end = token_terminator(start);

                printf("First token: ");

                while (start < end) {
                    putchar(*start);
                    start++;
                }

                putchar('\n');
            }
            else {
                printf("No tokens found.\n");
            }

            break;
        }

        case 5:
            printf("Enter a string:\n> ");
            fgets(input, sizeof(input), stdin);

            // Remove newline
            int i = 0;
            while (input[i] != '\0') {
                if (input[i] == '\n') {
                    input[i] = '\0';
                    break;
                }
                i++;
            }

            printf("Number of tokens = %d\n",
                   count_tokens(input));

            break;

        case 6: {
            printf("Enter a string:\n> ");
            fgets(input, sizeof(input), stdin);

            // Remove newline
            int i = 0;
            while (input[i] != '\0') {
                if (input[i] == '\n') {
                    input[i] = '\0';
                    break;
                }
                i++;
            }

            char **tokens = tokenize(input);

            printf("\nTokens:\n");
            print_tokens(tokens);

            free_tokens(tokens);

            break;
        }

        case 7: {
            printf("Enter a string:\n> ");
            fgets(input, sizeof(input), stdin);

            // Remove newline
            int i = 0;
            while (input[i] != '\0') {
                if (input[i] == '\n') {
                    input[i] = '\0';
                    break;
                }
                i++;
            }

            int len;

            printf("Enter number of characters to copy: ");
            scanf("%d", &len);
            getchar();

            char *copy = copy_str(input, len);

            printf("Copied string: %s\n", copy);

            free(copy);

            break;
        }

        case 0:
            printf("Goodbye!\n");
            return 0;

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}
