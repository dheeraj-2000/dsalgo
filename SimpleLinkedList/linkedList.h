#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* Next;
    int v;
};
typedef struct Node Node;

typedef struct {
    Node* begin;
} List;

// create new List pointer
List* createList();

// Add information to the list
void add(List* l, int valor); 

// print all elements in the list
void printList(List* l);

// check if list is empty
int isEmpty(List* l);

// remove last element from list
void removeBack(List* l);

// get the list size
int size(List* l);

// Check if an element exists
int hasElement(List* l, int value);

int insertPosition(List* l, int value, int position);

