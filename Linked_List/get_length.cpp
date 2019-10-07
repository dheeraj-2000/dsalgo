#include<bits/stdc++.h>
using namespace std;

class Node{
public:
      int data;
      Node* next;
};
void add_node(Node** head_ref, int new_data){
      Node* new_node = new Node();
      new_node->data = new_data;
      new_node->next = *head_ref;
      *head_ref = new_node;
}
void count_len(Node* n){
      int count=0;
      while(n!=NULL){
            count++;
            n=n->next;
      }
      cout<<count<<endl;
}


int main(){
      Node* head = NULL;

      add_node(&head, 8);
      add_node(&head, 2);
      add_node(&head, 1);
      add_node(&head, 9);
      cout<<"length of the list is: ";
      count_len(head);
}
