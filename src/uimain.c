#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
    List *history = init_history();

    int choice;
    char input[256];

    while (1)
    {
        printf("\n===== TOKENIZER =====\n");
        printf("1. Test space_char()\n");
        printf("2. Test non_space_char()\n");
        printf("3. Test token_start()\n");
        printf("4. Test token_terminator()\n");
        printf("5. Test count_tokens()\n");
        printf("6. Test tokenize()\n");
        printf("7. Test copy_str()\n");
        printf("8. Add to history\n");
        printf("9. Print history\n");
        printf("10. Get history by ID\n");
        printf("0. Quit\n");
        printf("> ");

        scanf("%d", &choice);
        getchar();      // Remove newline left by scanf

        switch(choice)
        {

        case 1:
            printf("Enter one character: ");
            fgets(input, sizeof(input), stdin);

            printf("space_char('%c') = %d\n",
                   input[0], space_char(input[0]));
	    add_history(history, input);
            break;


        case 2:
            printf("Enter one character: ");
            fgets(input, sizeof(input), stdin);

            printf("non_space_char('%c') = %d\n",
                   input[0], non_space_char(input[0]));
	    add_history(history, input);
            break;


        case 3:
        {
            printf("Enter a string: ");
            fgets(input, sizeof(input), stdin);

            for(int i = 0; input[i] != '\0'; i++)
                if(input[i] == '\n')
                    input[i] = '\0';

	    add_history(history, input);
            char *start = token_start(input);

            if(start)
                printf("First token begins with '%c'\n", *start);
            else
                printf("No tokens found.\n");

            break;
        }


        case 4:
        {
            printf("Enter a string: ");
            fgets(input, sizeof(input), stdin);

            for(int i=0; input[i] != '\0'; i++)
                if(input[i]=='\n')
                    input[i]='\0';
	    add_history(history, input);

            char *start = token_start(input);

            if(start)
            {
                char *end = token_terminator(start);
                printf("Token length = %ld\n", end-start);
            }
            else
                printf("No tokens found.\n");

            break;
        }


        case 5:
            printf("Enter a string: ");
            fgets(input,sizeof(input),stdin);

            for(int i=0; input[i] != '\0'; i++)
                if(input[i]=='\n')
                    input[i]='\0';
	    add_history(history, input);

            printf("Number of tokens = %d\n",
                   count_tokens(input));

            break;


        case 6:
        {
            printf("Enter a string: ");
            fgets(input,sizeof(input),stdin);

            for(int i=0; input[i] != '\0'; i++)
                if(input[i]=='\n')
                    input[i]='\0';

            /* Automatically store every tokenized string */
            add_history(history, input);

            char **tokens = tokenize(input);

            printf("\nTokens:\n");
            print_tokens(tokens);

            free_tokens(tokens);

            break;
        }


        case 7:
        {
            printf("Enter a string: ");
            fgets(input,sizeof(input),stdin);

            for(int i=0; input[i] != '\0'; i++)
                if(input[i]=='\n')
                    input[i]='\0';

	    add_history(history, input);
            char *copy = copy_str(input, token_terminator(input)-input);

            printf("Copied string: %s\n", copy);

            free(copy);

            break;
        }


        case 8:
            printf("Enter a string to add to history: ");
            fgets(input,sizeof(input),stdin);

            for(int i=0; input[i] != '\0'; i++)
                if(input[i]=='\n')
                    input[i]='\0';

            add_history(history,input);

            printf("Added to history.\n");

            break;


        case 9:
            printf("\nHistory:\n");
            print_history(history);
            break;


        case 10:
        {
            int id;

            printf("Enter history ID: ");
            scanf("%d",&id);
            getchar();

            char *result = get_history(history,id);

            if(result)
            {
                printf("\nHistory Item %d:\n%s\n",id,result);

                printf("\nTokenized:\n");

                char **tokens = tokenize(result);
                print_tokens(tokens);
                free_tokens(tokens);
            }
            else
            {
                printf("History item not found.\n");
            }

            break;
        }


        case 0:
            free_history(history);
            printf("Goodbye!\n");
            return 0;


        default:
            printf("Invalid option.\n");
        }
    }
}
