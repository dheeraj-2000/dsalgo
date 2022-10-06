//This code performs addition and multiplication on two polynomials.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//use malloc then check if this is working...
struct Node 
{
    float coeff;    
    int power;
    struct Node* next;
};
void create_node(float coeff, int power, struct Node** start)
{
    struct Node* newnode; 
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;
    if (*start == NULL)
    {
        *start = newnode;
        newnode->next = NULL;
    }
    else 
    {
        struct Node* ptr = *start;
        while (ptr->next != NULL)
        ptr = ptr->next;
        ptr->next = newnode;
        newnode->next = NULL;
    }
}
void show(struct Node* ptr)
{
    while (ptr != NULL) 
    {
        if(ptr->power>0)
            printf(" %.2fx^%d ",(double)abs(ptr->coeff),ptr->power);
        if(ptr->power<0)
            printf(" %f ",(double)abs(ptr->coeff));
        if( ptr->next!=NULL)
        {
            if(ptr->next->coeff >= 0)
            printf("+");
            else
            printf("-");
        }
        ptr = ptr->next;
    }
    printf("\n");
}
struct Node* removeDuplicates(struct Node* start)
{
    struct Node *ptr1, *ptr2, *duplicate;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL) 
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL) 
        {
            if (ptr1->power == ptr2->next->power) 
            {
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                duplicate = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(duplicate);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
struct Node* multiply(struct Node* poly1, struct Node* poly2,struct Node* poly3)
{
    struct Node *ptr1, *ptr2;
    ptr1 = poly1;
    ptr2 = poly2;
    while (ptr1 != NULL) 
    {
        while (ptr2 != NULL) 
        {
            int coeff, power;
            coeff = ptr1->coeff * ptr2->coeff;
            power = ptr1->power + ptr2->power;
            create_node(coeff, power, &poly3);
            ptr2 = ptr2->next;
        }
        ptr2 = poly2;
        ptr1 = ptr1->next;
    }
    poly3=removeDuplicates(poly3);
    return poly3;
}
struct Node* add(struct Node* poly1,struct Node* poly2, struct Node* poly4)
{
    struct Node *pt1,*pt2;
    pt1=poly1;
    pt2=poly2;
    while(pt1!=NULL&&pt2!=NULL)
    {
        if(pt1->power>pt2->power)
        {
            create_node(pt1->coeff,pt1->power,&poly4);
            pt1=pt1->next;
        }
        else if(pt1->power<pt2->power)
        {
            create_node(pt2->coeff,pt2->power,&poly4);
            pt2=pt2->next;
        }
        else
        {
            create_node(((pt1->coeff)+(pt2->coeff)),pt1->power, &poly4);
            pt1=pt1->next;
            pt2=pt2->next;
        }
    }
    while(pt1!=NULL||pt2!=NULL)
    {
        if(pt1!=NULL)
        {
            create_node(pt1->coeff,pt1->power, &poly4);
            pt1=pt1->next;
        }
        else if(pt2!=NULL)
        {
            create_node(pt2->coeff,pt2->power, &poly4);
            pt2=pt2->next;
        }
    }
    return poly4;
}
int main()
{
    int option,power;
    float coeff;
    int opt;
    do
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL,*poly4=NULL; 
        printf("1. Enter the value of polynomials.\n");
        printf("2. Exit.\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                do
                {
                    printf("\nEnter coeff and power of 1st polynomial: ");
                    scanf("%f %d",&coeff,&power);
                    create_node(coeff,power,&poly1);
                    printf("\nContinue to add more nodes y=1/n=0:");
                    scanf("%d",&opt);
                }while(opt==1);
                do
                {
                    printf("Enter coeff and power of 2nd polynomial: ");
                    scanf("%f %d",&coeff,&power);
                    create_node(coeff,power,&poly2);
                    printf("Continue to add more nodes y=1/n=0:");
                    scanf("%d",&opt);
                }while(opt==1);
                poly1=removeDuplicates(poly1);
                show(poly1);
                poly2=removeDuplicates(poly2);
                show(poly2);
                poly3=multiply(poly1,poly2,poly3);
                printf("Product: ");
                poly3=removeDuplicates(poly3);
                show(poly3);
                poly4=add(poly1,poly2,poly4);
                printf("Sum: ");
                poly4=removeDuplicates(poly4);
                show(poly4);
                break;
        }
    } while (option!=2);
    return 0;
}