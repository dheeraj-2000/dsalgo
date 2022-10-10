#include<iostream>
using namespace std;
class Queue
{
	int *arr,length;
	int rear,front;
	public:
	Queue()
	{
		cout<<"Enter length of array:";
		cin>>length;
		arr=new int [length];
		rear=front=-1;
	}
	void insert()
	{
		if(rear==length-1 && front==0|| rear==front-1)
		{
			cout<<"Queue overflow!";
		}
		else if(rear==-1 && front==-1)
		{
			int a;
			cout<<"Enter element:";
			cin>>a;
			rear=rear+1;
			front=front+1;
			arr[rear]=a;
		}
		else if(front!=0 && rear==length-1)
		{
			int a;
			cout<<"Enter element:";
			cin>>a;
			rear=0;
			arr[rear]=a;
		}
		else
		{
			int a;
			cout<<"Enter element:";
			cin>>a;
			rear=rear+1;
			arr[rear]=a;
		}
	}
	void del()
	{
		if(front==-1 && rear==-1)
		{
			cout<<"Queue underflow!";
		}
		else if(front==rear)
		{
			cout<<"Dequeued element="<<arr[front];
			front=rear=-1;
		}
		else if(front==length-1)
		{
			cout<<"Dequeued element="<<arr[front];
			front=0;
		}	
		else
		{
			cout<<"Dequeued element="<<arr[front];
			front=front+1;
		}
	}
	void display()
	{
		if(front==-1 && rear==-1)
		{
			cout<<"Queue underflow!";
			return;
		}
		cout<<"Elements of Queue:";
		if(front<=rear)
		{
			int front1=front;
			while(front1!=rear)
			{
				cout<<arr[front1]<<" ";
				front1=front1+1;
			}
			cout<<arr[front1];
		}
		else{
			int i;
			for(i=front;i<length;i++)
			{
				cout<<arr[i]<<" ";
			}
			for(i=0;i<=rear;i++)
			{
				cout<<arr[i]<<" ";
			}
		}

	}
};
int main()
{
	Queue q;
	int ch;
	while(true)
	{
		cout<<"\nChoices:\n1.Insert an element.\n2.Delete an element.\n3.Display.\n4.Exit";
		cout<<"\nWhat u wanna do?";
		cin>>ch;
		switch(ch)
		{
			case 1:
			q.insert();
			break;
			case 2:
			q.del();
			break;
			case 3:
			q.display();
			break;
			case 4:
			exit(0);
			break;
		}
	}
}