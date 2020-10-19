#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main (void) {
    List *lista = createList();
    if(isEmpty) printf("Empty list\n");

    add(lista, 10);
    add(lista, 20);
    add(lista, 30);
    add(lista, 40);
    add(lista, 50); 
    printList(lista);

    removeBack(lista);
    printList(lista);
    printf("Lenght: %d\n\n", size(lista)); 

    removeBack(lista);
    printList(lista);
    printf("Length: %d\n\n", size(lista)); 

    add(lista, 60);
    printf("Length: %d\n\n", size(lista)); 
    printList(lista);

    removeBack(lista);
    printf("Length: %d\n\n", size(lista)); 
    removeBack(lista);

    printList(lista);
    printf("Length: %d\n\n", size(lista)); 
    removeBack(lista);

    printList(lista);
    printf("Length: %d\n\n", size(lista)); 

    removeBack(lista);
    printList(lista);

    if(isEmpty(lista)) printf("Empty list\n");
    printf("Length: %d\n\n", size(lista)); 
    return 0;
}
