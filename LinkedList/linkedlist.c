#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void init(LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    printf("\nList initialized\n\n");
}

void add(struct LinkedList *list, int element)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->element = element;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = (struct Node *)newNode;
        list->tail = newNode;
    }
    list->size++;

    printf("Element %d added\n", element);
}

void addAtIndex(LinkedList *list, int index, int element)
{
    if (index < 0 || index > list->size)
    {
        printf("Index out of bounds\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->element = element;
    newNode->next = NULL;

    if (index == 0) // add at head
    {
        newNode->next = (struct Node *)list->head;
        list->head = newNode;
    }
    else if (index == list->size) // add at tail
    {
        list->tail->next = (struct Node *)newNode;
        list->tail = newNode;
    }
    else // add at middle
    {
        Node *current = list->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = (Node *)current->next;
        }
        newNode->next = current->next;
        current->next = (struct Node *)newNode;
    }
    list->size++;

    printf("Element %d added at index %d\n", element, index);
}

void removeByIndex(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        printf("Index out of bounds\n");
        return;
    }

    Node *current = list->head;
    Node *previous = NULL;
    for (int i = 0; i < index; i++)
    {
        previous = current;
        current = (Node *)current->next;
    }

    if (previous == NULL) // remove head
    {
        list->head = (Node *)current->next;
    }
    else // remove middle or tail
    {
        previous->next = current->next;
    }

    if (current->next == NULL) // updates tail if needed
    {
        list->tail = previous;
    }

    free(current);
    list->size--;

    printf("Element at index %d removed\n", index);
}

void removeByElement(LinkedList *list, int element)
{
    int index = indexOf(list, element);
    if (index != -1)
        removeByIndex(list, index);
}

int indexOf(LinkedList *list, int element)
{
    Node *current = list->head;
    int index = 0;
    while (current != NULL)
    {
        if (current->element == element)
        {
            printf("Element %d found at index %d\n", element, index);
            return index;
        }

        current = (Node *)current->next;
        index++;
    }
    return -1;

    printf("Element %d not found\n", element);
}

void printList(LinkedList *list)
{
    Node *current = list->head;
    printf("\nList: [");
    while (current != NULL)
    {
        if (current->next == NULL)
        {
            printf("%d]\n", current->element);
            break;
        }
        printf("%d, ", current->element);
        current = (Node *)current->next;
    }
    printf("\n");
}

void clean(LinkedList *list)
{
    Node *current = list->head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = (Node *)current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    printf("List cleaned\n\n");
}