#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main (void) {
    List *list = createList();
    if(isEmpty) printf("Empty list\n");

    add(list, 10);
    add(list, 20);
    add(list, 30);
    add(list, 40);
    add(list, 50); 
    printList(list);

    int testList[] = {10, 45, 56, 20};

    for(int item = 0; item < 4; item++) {
        if(hasElement(list, testList[item]) != -1)
            printf("%d exists on list!\n", testList[item]);
    }

    removeBack(list);
    printList(list);
    printf("Lenght: %d\n\n", size(list)); 

    removeBack(list);
    printList(list);
    printf("Length: %d\n\n", size(list)); 

    add(list, 60);
    printf("Length: %d\n\n", size(list)); 
    printList(list);

    removeBack(list);
    printf("Length: %d\n\n", size(list)); 
    removeBack(list);

    printList(list);
    printf("Length: %d\n\n", size(list)); 
    removeBack(list);

    printList(list);
    printf("Length: %d\n\n", size(list)); 

    removeBack(list);
    printList(list);

    if(isEmpty(list)) printf("Empty list\n");
    printf("Length: %d\n\n", size(list));

    // insert on specific position
    add(list, 100);
    add(list, 102);
    add(list, 103);
    printList(list);
    insertPosition(list, 101, 1);
    printList(list);
    removePosition(list, 1);
    printList(list);
    return 0;
}

