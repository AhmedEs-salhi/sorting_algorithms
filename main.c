#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

void swapNodes(listint_t *) {

    listint_t *currX = *head;
    listint_t *prevX = NULL;
    while (currX != NULL && currX->n != x) {
        prevX = currX;
        currX = currX->next;
    }

    listint_t *currY = *head;
    listint_t *prevY = NULL;
    while (currY != NULL && currY->n != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return;

    if (prevX != NULL)
        prevX->next = currY;
    else
        *head = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        *head = currX;

    listint_t *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    listint_t *one, *two, *temp;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);

    one = list->next;
    two = one->next;
    printf("one's old position: [%d] -> [%d] -> [%d]\n", one->prev->n, one->n, one->next->n);
    printf("two: [%d]\n", two->n);

    print_list(list);
    swapNodes(&list, 48, 99); 

    //print_list(list);
    //printf("\n");
    //insertion_sort_list(&list);
    printf("one's new position: [%d] -> [%d] -> [%d]\n", one->prev->n, one->n, one->next->n);
    printf("two: [%d]\n");
    print_list(list);
    return (0);
}
