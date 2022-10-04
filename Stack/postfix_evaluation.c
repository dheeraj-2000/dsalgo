#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 20
int stack[MAX];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char expr[20], x;
    int n1, n2, n3, num, i;
    printf("Enter the Postfix Expression: ");
    fflush(stdin);
    gets(expr);
    for(i = 0; i < strlen(expr); i++)
    {
        x = expr[i];
        if(isdigit(x))
        {
            num = (x - 48);
            push(num);
        }
        else if(x == ' ')
            continue;
        else
        {
            n1 = pop();
            n2 = pop();
            switch(x)
            {
                case '+':
                {
                    n3 = n2 + n1;
                    break;
                }
                case '-':
                {
                    n3 = n2 - n1;
                    break;
                }
                case '*':
                {
                    n3 = n2 * n1;
                    break;
                }
                case '/':
                {
                    n3 = n2 / n1;
                    break;
                }
                case '^':
                {
                    n3 = pow(n2, n1);
                    break;
                }
                default:
                {
                    printf("Invalid Expression!\n");
                    break;
                }
            }
            push(n3);
        }
    }
    printf("\nThe result of expression %s  =  %d\n\n", expr, pop());
    return 0;
}
