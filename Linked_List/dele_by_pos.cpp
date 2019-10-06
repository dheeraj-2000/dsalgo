#include<bits/stdc++.h>
using namespace std;

class Node{                            //details about a node
public:
      int data;
      Node* next;
};


void add_node(Node** head_ref, int new_data){             //add the node
      Node* new_node = new Node();
      new_node->data = new_data;
      new_node->next = *head_ref;
      *head_ref = new_node;
}

void delete_key(Node** head_ref, int key) {                  //delete the node by its position
      if(*head_ref ==NULL)
            return;
      Node* temp = *head_ref;

      if(key ==0){
            *head_ref = temp->next;
            free(temp);
            return;
      }

      for(int i=0; temp!=NULL && i<key-1; i++ ){
            temp=temp->next;
      }

      if(temp==NULL || temp->next==NULL)
            return;

      Node* next = temp->next->next;
      free(temp->next);
      temp->next = next;



}

void print_node(Node* n){                                   //print the node
      while(n!=NULL){
            cout<< n->data<<endl;
            n=n->next;
      }
}

int main(){                                                   //driver function
      Node* head = NULL;

      add_node(&head, 8);
      add_node(&head, 7);
      add_node(&head, 3);
      add_node(&head, 4);
      add_node(&head, 9);

       cout<<"Original linked list is: "<<endl;
        print_node(head);
        delete_key(&head, 4);
        cout<<"linked list after deltion is: "<<endl;
        print_node(head);
}
