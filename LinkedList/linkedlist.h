#ifndef LINKEDLIST
#define LINKEDLIST

// Structs definition
typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node
{
    int element;
    Node *next;
};

struct LinkedList
{
    Node *head;
    Node *tail;
    int size;
};

// Function prototypes
void init(LinkedList *list);
void add(LinkedList *list, int element);
void addAtIndex(LinkedList *list, int index, int element);
void removeByIndex(LinkedList *list, int index);
void removeByElement(LinkedList *list, int element);
int indexOf(LinkedList *list, int element);
void printList(LinkedList *list);
void clean(LinkedList *list);

#endif