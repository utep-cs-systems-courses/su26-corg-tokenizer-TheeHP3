#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true if c is a space or tab and not the null terminator */
int space_char(char c)
{
    return c != '\0' && (c == ' ' || c == '\t');
}

/* Return true if c is not a space, tab, or null terminator */
int non_space_char(char c)
{
    return c != '\0' && c != ' ' && c != '\t';
}

/* Return pointer to first character of next token.
   Return 0 if there are no tokens. */
char *token_start(char *str)
{
    /* Skip leading whitespace */
    while (*str && space_char(*str))
        str++;

    /* If we reached end of string, there are no tokens */
    if (*str == '\0')
        return 0;

    return str;
}

/* Return pointer to character immediately after the token */
char *token_terminator(char *token)
{
    /* Move forward until whitespace or end of string */
    while (*token && non_space_char(*token))
        token++;

    return token;
}

/* Count number of tokens in a string */
int count_tokens(char *str)
{
    int count = 0;

    char *current = token_start(str);

    while (current != 0) {
        count++;

        /* Move to the end of the current token */
        current = token_terminator(current);

        /* Find the start of the next token */
        current = token_start(current);
    }

    return count;
}

/* Allocate and return a copy of len characters from inStr */
char *copy_str(char *inStr, short len)
{
    /* +1 for the null terminator */
    char *copy = (char *)malloc(len + 1);

    if (copy == 0)
        return 0;

    for (int i = 0; i < len; i++)
        copy[i] = inStr[i];

    /* Every C string must end with '\0' */
    copy[len] = '\0';

    return copy;
}

char **tokenize(char *s)
{
    int num_tokens = count_tokens(s);

    // +1 for NULL sentinel at end
    char **tokens = malloc(sizeof(char *) * (num_tokens + 1));

    if (tokens == NULL)
        return NULL;

    int i = 0;

    char *current = token_start(s);

    while (current != NULL && i < num_tokens)
    {
        char *end = token_terminator(current);
        int len = end - current;

        tokens[i] = copy_str(current, len);

        i++;

        current = token_start(end);
    }

    tokens[i] = NULL; // important sentinel

    return tokens;
}

/*
 * print_tokens:
 * Prints each token line by line
 */
void print_tokens(char **tokens)
{
    int i = 0;

    while (tokens[i] != NULL)
    {
        printf("%s\n", tokens[i]);
        i++;
    }
}

/*
 * free_tokens:
 * Frees each token string and then the array itself
 */
void free_tokens(char **tokens)
{
    int i = 0;

    while (tokens[i] != NULL)
    {
        free(tokens[i]);
        i++;
    }

    free(tokens);
}
