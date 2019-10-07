#include<bits/stdc++.h>
using namespace std;

class Node{
public:
      int data;
      Node* next;
};

void delete_list(Node** head_ref){
      Node* temp = *head_ref;
      Node* next;
      while(temp!=NULL){
            next = temp->next;
            free(temp);
            temp = next;

      }
      *head_ref = NULL;
}

void add_node(Node** head_ref, int new_data){             //add the node
      Node* new_node = new Node();
      new_node->data = new_data;
      new_node->next = *head_ref;
      *head_ref = new_node;
}

void print_node(Node* n){
      while(n!=NULL){
            cout<< n->data<<endl;
            n=n->next;
      }
}
int main(){
      Node* head = NULL;

      add_node(&head, 9);
      add_node(&head, 8);
      add_node(&head, 5);
      add_node(&head, 3);
      add_node(&head, 1);

      print_node(head);
      cout<<"deleting node"<<endl;
      delete_list(&head);
      cout<<"deleted list"<<endl;
      print_node(head);
}
