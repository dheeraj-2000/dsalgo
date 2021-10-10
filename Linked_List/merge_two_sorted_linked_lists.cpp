#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#include <functional>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node() {
            this->next = NULL;
        }

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList {
    public:
        Node* head = NULL;

        void insert_at_beg(int data){
            Node* temp = new Node(data);
            temp->next = this->head;
            this->head = temp;
        }

        void print_data(){
            Node* itr = this->head;

            while(itr != NULL){
                cout << itr->data << "->";
                itr = itr->next;
            }
            cout <<"end"<< endl;
        }
};

Node* merge_2_sorted_list(LinkedList* l1,LinkedList* l2){
	if(l1->head==NULL || l2->head==NULL)
		return l1->head==NULL ? l2->head : l1->head;
	Node *dummy = new Node(-1);
	Node *previous = dummy, *c1 = l1->head, *c2 = l2->head;
	while(c1 != NULL && c2 != NULL)
	{
		if(c1->data <= c2->data)
		{
			previous->next = c1;
			c1 = c1->next;
		}
		else
		{
			previous->next = c2;
			c2 = c2->next;
		}
		previous = previous->next;
	}
	previous->next = c1 != NULL ? c1 : c2;
	Node *head = dummy->next;
	dummy->next = NULL;
	delete(dummy);
	return head;
}

int main()
{
	LinkedList* list1 = new LinkedList();
	LinkedList* list2 = new LinkedList();

    // Create Linked list 1
    list1->insert_at_beg(18);
    list1->insert_at_beg(12);
    list1->insert_at_beg(9);
    list1->insert_at_beg(4);
    list1->insert_at_beg(3);
    list1->insert_at_beg(1);
    list1->insert_at_beg(1);

    // Create Linked list 2
    list2->insert_at_beg(22);
    list2->insert_at_beg(21);
    list2->insert_at_beg(16);
    list2->insert_at_beg(7);
    list2->insert_at_beg(3);

    cout<<"Linked List 1 data:\n";
    list1->print_data();

    cout<<"\nLinked List 2 data:\n";
    list2->print_data();

    Node *merged_list = merge_2_sorted_list(list1, list2);
	
	cout<<"\nMerged Linked List data:\n";
	Node *temp = merged_list;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"end";

	return 0;
}