#include <stdio.h>
#include <tokenizer.h>

int main()
{
    char str[] = "  hello   world  test ";

    printf("Tokens: %d\n", count_tokens(str));

    char *start = token_start(str);

    if (start)
        printf("First token begins with: %c\n", *start);

        printf("space_char(' ') = %d\n", space_char(' '));
        printf("space_char('a') = %d\n", space_char('a'));

        printf("non_space_char('a') = %d\n", non_space_char('a'));
        printf("non_space_char(' ') = %d\n", non_space_char(' '));

        printf("count_tokens = %d\n", count_tokens(str));

    	char input[] = "this is a test";
    	char **tokens = tokenize(input);

    	print_tokens(tokens);
    	free_tokens(tokens);

    return 0;
}
