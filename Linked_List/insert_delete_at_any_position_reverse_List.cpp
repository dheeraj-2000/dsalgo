//append at start, end, specific position
//left->  sort, swap 2 nodes
#include<iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;
};

node* newNode(int data)
{
    node* new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append(node** head_ref, int data)
{
    node* temp = *head_ref;
    if(*head_ref == NULL)
        *head_ref = newNode(data);
    else
    {
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode(data);
    }
}

void append_at_start(node** head_ref, int data)
{
    node* temp = *head_ref;
    node* newnode = newNode(data);
    *head_ref = newnode;
    newnode->next = temp;
}

void append_at_position(node** head_ref, int pos, int data)
{
    int i = 0;
    node *temp = *head_ref, *newnode = newNode(data);;
    if(*head_ref == NULL)
    {
        *head_ref = newnode;
        return;
    }
    if(pos == 1)
    {
        newnode->next = *head_ref;
        *head_ref = newnode;
        return;
    }
    while(i < pos-2 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if(temp == NULL)
    {
        cout << "Cann't Add, Invalid Position\n";
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void popStart(node** head_ref)
{
    if(*head_ref == NULL)
    {
     cout << "Empty List\n";
        return;
    }
    *head_ref = (*head_ref)->next;
}

void popLast(node** head_ref)
{
    node* temp = *head_ref;
    if(*head_ref == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    if(temp->next == NULL)
    {
        *head_ref = NULL;
        return;
    }
    while(temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
}

void popPosition(node** head_ref, int pos)
{
    int i = 0;
    node* temp = *head_ref;
    if(*head_ref == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    if(pos == 1)
    {
        *head_ref = (*head_ref)->next;
        return;
    }
    while(i < pos-2 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if(temp == NULL || temp->next == NULL)
    {
        cout << "Cann't Pop, Invalid Position\n";
        return;
    }
    temp->next = temp->next->next;
}

void reverse_list(node** head_ref)
{
    node *current = *head_ref, *prev = NULL, *after = NULL;
    if(*head_ref == NULL)
        return;
    while(current != NULL)
    {
        after = current->next;
        current->next = prev;
        prev = current;
        current = after;
    }
    *head_ref = prev;
}
/*
void swap(node** head_ref, int x, int y)
{
    node *prev1 = NULL, *prev2 = NULL, *curr1 = *head_ref, *curr2 = *head_ref;
    if(x == y)
        return;
    while(curr1 && curr1->data != x)
    {
        prev1 = curr1;
        curr1 = curr1->next;
    }
    while(curr2 && curr2->data != y)
    {
        prev2 = curr2;
        curr2 = curr2->next;
    }
    if(curr1 == NULL || curr2 == NULL)
        return;
    if(prev1 != NULL)
        prev1->next = curr2;
    else
        *head_ref = curr2;
    if(prev2 != NULL)
        prev2->next = curr1;
    else
        *head_ref = curr1;
    node* temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}
*/
void print(node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node* head = NULL;
    append(&head, 6);
    append(&head, 7);
    append(&head, 8);
    append(&head, 9);
    append(&head, 10);
    append(&head, 11);
    append_at_start(&head, 1);
    append_at_position(&head, 4, 10);
    popStart(&head);
    popLast(&head);
    popPosition(&head, 6);
    print(head);
    reverse_list(&head);
    //swap(&head, 7, 11);
    print(head);
    return 0;
}
