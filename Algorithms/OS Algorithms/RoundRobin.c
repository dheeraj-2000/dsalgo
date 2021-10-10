//  Round robin Scheduling algorithm using circular linkedlist queue in c language..

#include<stdio.h>
#include<stdlib.h>

// linkedlist node. 
struct node {
    int id;
    int arrivalTime;
    int brustTime;
    struct node* next;
    struct node* prev;

}*head, *nextNode, *previousNode, *lastNode;


// inserting node in sorted order according to arrival time...
void insertNode(int id, int arrive, int brust){
    // pushing the first node....
    if(head==NULL){
        head = (struct node *)malloc(sizeof(struct node));
        head->id = id;
        head->arrivalTime = arrive;
        head->brustTime = brust;
        head->next = NULL;
        head->prev = NULL;
    
    }else {
        nextNode = (struct node *)malloc(sizeof(struct node));
        nextNode->id = id;
        nextNode->arrivalTime = arrive;
        nextNode->brustTime = brust;

        struct node *ptr = head;
        previousNode = NULL;
        while(ptr != NULL){
            
            if(ptr->arrivalTime > arrive){
                // if it is head
                if(previousNode == NULL){
                    nextNode->next  = head;
                    nextNode->prev  = NULL;
                    head->prev      = nextNode;
                    
                    head = nextNode;
                
                } else{
                    nextNode->next  = ptr;
                    nextNode->prev  = previousNode;

                    previousNode->next  = nextNode;
                    ptr->prev           = nextNode;
                }
                return;
            }
            previousNode = ptr;
            ptr = ptr->next;
        }
        // inserting at the end
        nextNode->next = NULL;
        nextNode->prev = previousNode;
        previousNode->next = nextNode;
        
    }
}

void insert_end(int id, int arrive, int brust){
    nextNode = (struct node *)malloc(sizeof(struct node));
    nextNode->id = id;
    nextNode->arrivalTime = arrive;
    nextNode->brustTime = brust;
    nextNode->next = NULL;
    nextNode->prev = lastNode;

    lastNode->next = nextNode;
    lastNode = nextNode;
}

// delete a perticular node..
void deleteNode(int pid){
    struct node *ptr = head;
    while(ptr != NULL){
        if(ptr->id == pid){
            // if its head
            if(ptr == head){
                // if it is only
                if(ptr->next != NULL){
                    ptr->next->prev = NULL;
                    head = ptr->next;
                }
                free(ptr);
            
            // if it is a tail..
            }else if(ptr->next == NULL){
                ptr->prev->next = NULL;
                free(ptr);
            
            }else{
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr);
            }
            return;
        }
        ptr = ptr->next;
    }
}

void RR_schedule(int PT){
    struct node *ptr = head;
    struct node *temp;
    int totalTime = head->arrivalTime;

    while(ptr != NULL){
        temp = ptr;      
        ptr->brustTime = ptr->brustTime - PT;
        // if task completed..
        if(ptr->brustTime <= 0 || ptr->next == NULL){
            // if that is only node.
            if(ptr->next == NULL){
                printf("|P%d [%d-%d]|", temp->id, totalTime, totalTime+PT+ptr->brustTime);
                deleteNode(ptr->id);
                return;
            }
            ptr = ptr->next;
            printf("|P%d [%d-%d]|", temp->id, totalTime, totalTime+PT+temp->brustTime);
            totalTime = totalTime + PT + temp->brustTime;
            deleteNode(temp->id);
            

        } else{
            insert_end(ptr->id, ptr->arrivalTime, ptr->brustTime);
            ptr = ptr->next;
            printf("|P%d [%d-%d]|", temp->id, totalTime, totalTime+PT);
            totalTime += PT;
            deleteNode(temp->id);
        }
    }
}


int main(){

    lastNode = (struct node *)malloc(sizeof(struct node));

    int n, pid, AT, BT, QT;
    printf(" \n Enter quantum share Time : ");
    scanf("%d", &QT);

    printf(" \n Enter number of process : ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf(" \n Enter process id, Arrival Time, Brust Time respectively [ ex- 1 0 20 ] : ");
        scanf("%d %d %d" , &pid, &AT, &BT);
        insertNode(pid, AT, BT);
    }

    // moving to the last node..
    lastNode = head;
    while(lastNode->next != NULL){
        lastNode = lastNode->next;
    }
    printf("\n");
    RR_schedule(QT);
    printf("\n");

    return 0;
}

// end
