#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

List* createList() {
    // lets create our list in memory
    List* L = (List*) malloc(sizeof(List));

    // operation success?
    if(L == NULL) return NULL;

    // set the main node to NULL (empty list)
    L->begin = NULL;
    return L;
}

void add(List* l, int value) {
    // creating a new node pointer in memory to add to list
    Node* node = (Node*) malloc(sizeof(Node));

    // previously and actual node
    Node *a, *p;

    // is that first element of list? Yes, So make it header
    node->v = value;
    if(l->begin == NULL)  {
        l->begin = node;
        node->Next = NULL;
    }

    // No, so put it on the end of list
    else {
        p = l->begin;
        a = p;
        while(p != NULL) {
            a = p;
            p = p->Next;
        }
        a->Next = node;
        node->Next = NULL;
    }
}

// for every node, print his value
void printList(List* l) {
    Node* p = l->begin;
    if(p != NULL) {
        do {
            printf("%d ", p->v);
            p = p->Next;
        } while(p != NULL);
        printf("\n");
    }
}

// it is only necessary to check if the list header is null
int isEmpty(List* l){
    return (l->begin == NULL);
}

void removeBack(List* l) {
    // previously and actual node
    Node *p, *a; 
    p = l->begin;
    a = p;
    
    //There is only 1 node?
    if(p->Next == NULL) {
        l->begin = NULL;
        return;
    }

    // go to the last node and mark the previous node as NULL
    while(p->Next != NULL) {
        a = p;
        p = p->Next;
    }
    a->Next = NULL;

    // clean node from memory
    free(p);
}

int size(List* l) {
    Node* p = l->begin;
    int length = 0;
    
    // list is empty?
    if(isEmpty(l)) return 0;

    // count until reach the last node
    while(p != NULL) {
        p = p->Next;
        length++;
    }
    return length; 
}

int hasElement(List* l, int value) {
    int pos = 0;
    Node *p = l->begin;
    while(p != NULL) {
        if(p->v == value) return pos;
        pos++;
        p = p->Next;
    }
    return -1;
}

int insertPosition(List* l, int value, int position) {
    Node *node = (Node*) malloc(sizeof(Node));
    Node *p, *bef;
    int count = 0;
    node->v = value;    
    p = bef = l->begin;

    if(position >= 0) {
        if(position == 0) {
            if(l->begin == NULL) {
                l->begin = node;
                node->Next = NULL; 
            }
            else {
                l->begin = node;
                node->Next = p;
            }
        }
        else {
            while(p != NULL) {
                if(count == position) {
                    node->Next = p;
                    bef->Next = node;
                    return 0;
                }
                bef = p;
                p = p->Next;
                count++;
            }
        }
    }
    return -1;
}
