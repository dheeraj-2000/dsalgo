//Implementation of stack

#include <stdio.h>
#include<stdlib.h>

//declaring structure
struct stack
{
   int data;
   struct stack *ptr; //pointer type of stack
};

typedef struct stack Stack;
typedef Stack *stackPtr;

//function prototypes of different functions
void push(stackPtr *top, int x); //for pushing value in stack
int pop(stackPtr *top); //for popping value out of stack
int checkEmpty(stackPtr top); //checking whether stack is empty
void printValue(stackPtr showPtr); //for printing value that are pushed and popped

int main()
{
   stackPtr stackNewPtr = NULL; //declared pointer that points to the top of stack
   int option; //variable for choosing different options
   int value; //variable for storing entered by the user

   //different options for the user
   printf("\nPlease choose following options:\n");
   printf("1. PUSH\n");
   printf("2. POP\n");
   printf("3. EXIT\n");

   scanf("%d", &option);

   //program flow enters while loop if user enter value other than 3
   while (option != 3)
   {
      switch (option)
      {
      case 1:
         printf("\nEnter value: ");
         scanf("%d", &value);
         push(&stackNewPtr, value);
         printValue(stackNewPtr);
         break;

      case 2:
         if (!checkEmpty(stackNewPtr))
         {
            printf("\nPopped Value: %d\n", pop(&stackNewPtr));
         }
         printValue(stackNewPtr);
         break;

      default:
         puts("\n**Invalid choice**");
         break;
      }

      printf("\nWhat do you want: ");
      scanf("%d", &option);
   }
}

//function for pushing value into the top of stack
void push( stackPtr *top, int x )
{
    stackPtr nodePtr;

    //allocating memory
    nodePtr = malloc(sizeof(Stack));

    //pushing value at the top of stack only if there is space
    if(nodePtr != NULL)
    {
       nodePtr -> data = x;
       nodePtr -> ptr = *top;
       *top = nodePtr;
    }

    else
       printf("\nERROR !!! (Not enough space)");
   }

//popping value out of the stack
int pop(stackPtr *top)
{
   int pValue; //variable for value at the top
   stackPtr tempPtr; //temporary pointer

   tempPtr = *top;
   pValue = (*top) -> data;
   *top = (*top) -> ptr;
   free(tempPtr); //free temporary pointer value
   return pValue;
}

//function for printing value stored in the stack
void printValue(stackPtr showPtr)
{
   if(showPtr == NULL)
   {
       printf("\nNo value found.");
   }
   else
   {
      printf("\nData stored in stack:\n");

      while(showPtr != NULL)
     {
         printf("%d --> ", showPtr -> data);
         showPtr = showPtr -> ptr;
     }
     printf("NULL\n");
   }
}

int checkEmpty(stackPtr top)
{
   return top == NULL;
}
