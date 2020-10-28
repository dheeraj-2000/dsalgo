#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

struct Node
{
	char value[100];
	Node *next, *prev;
} * head[SIZE], *tail[SIZE];

int hash(char value[])
{
	int sum = 0;
	int len = strlen(value);
	
	for (int i=0;i<len;i++){
		sum += value[i] * i;
	}
	return sum % SIZE;
}

void insert(char value[])
{
	int key = hash(value);

	Node *curr = (Node *)malloc(sizeof(Node));
	strcpy(curr->value, value);
	curr->prev = curr->next = NULL;

	if (head[key] == NULL)
	{
		head[key] = tail[key] = curr;
	}
	else
	{
		curr->prev = tail[key];
		tail[key]->next = curr;
		tail[key] = curr;
	}
}

void popHead(int key)
{
	if (head[key])
	{
		if (head[key] == tail[key])
		{
			free(head[key]);
			head[key] = tail[key] = NULL;
		}
		else
		{
			head[key] = head[key]->next;
			free(head[key]->prev);
			head[key]->prev = NULL;
		}
	}
}

void popTail(int key)
{
	if (head[key])
	{
		if (head[key] == tail[key])
		{
			free(head[key]);
			head[key] = tail[key] = NULL;
		}
		else
		{
			tail[key] = tail[key]->prev;
			free(tail[key]->next);
			tail[key]->next = NULL;
		}
	}
}

void del(char value[])
{
	int key = hash(value);
	if (head[key])
	{
		if (strcmp(head[key]->value, value) == 0)
		{
			popHead(key);
		}
		else if (strcmp(tail[key]->value, value) == 0)
		{
			popTail(key);
		}
		else
		{
			Node *temp = head[key];
			while (temp && strcmp(temp->value, value) != 0)
			{
				temp = temp->next;
			}

			if (temp)
			{
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				free(temp);
			}
		}
	}
}

void printAll()
{

	for (int i = 0; i < SIZE; i++)
	{
		Node *temp = head[i];

		if (temp != NULL)
		{
			while (temp != NULL)
			{
				printf("%s -> ", temp->value);
				temp = temp->next;
			}
			printf("\n");
		}
	}
}

int main()
{
	insert("Andi");
	insert("Ansy");
	insert("Anto");
	insert("Budi");
	del("Andi");
	printAll();
	return 0;
}
