#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/*
 * Creates and initializes an empty history list.
 */
List *init_history()
{
    List *list = (List *)malloc(sizeof(List));

    if (list == NULL)
        return NULL;

    list->root = NULL;

    return list;
}

/*
 * Adds a new history item to the end of the linked list.
 */
void add_history(List *list, char *str)
{
    if (list == NULL || str == NULL)
        return;

    /* Allocate memory for the new history item */
    Item *newItem = (Item *)malloc(sizeof(Item));

    if (newItem == NULL)
        return;

    /* Determine length of the string manually
       (cannot use strlen()) */
    short len = 0;
    while (str[len] != '\0')
        len++;

    /* Make our own copy of the string */
    newItem->str = copy_str(str, len);

    newItem->next = NULL;

    /* If list is empty, this becomes the first node */
    if (list->root == NULL) {
        newItem->id = 1;
        list->root = newItem;
        return;
    }

    /* Otherwise, walk to the end of the list */
    Item *current = list->root;

    while (current->next != NULL)
        current = current->next;

    /* Assign the next ID */
    newItem->id = current->id + 1;

    /* Attach new node */
    current->next = newItem;
}

/*
 * Returns the string associated with a given history ID.
 * Returns NULL if the ID is not found.
 */
char *get_history(List *list, int id)
{
    if (list == NULL)
        return NULL;

    Item *current = list->root;

    while (current != NULL) {

        if (current->id == id)
            return current->str;

        current = current->next;
    }

    return NULL;
}

/*
 * Prints every history item.
 */
void print_history(List *list)
{
    if (list == NULL)
        return;

    Item *current = list->root;

    while (current != NULL) {

        printf("%d: %s\n", current->id, current->str);

        current = current->next;
    }
}

/*
 * Frees every node in the linked list, including the copied strings.
 */
void free_history(List *list)
{
    if (list == NULL)
        return;

    Item *current = list->root;

    while (current != NULL) {

        /* Save pointer before freeing current node */
        Item *next = current->next;

        free(current->str);
        free(current);

        current = next;
    }

    free(list);
}
