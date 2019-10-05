#include<bits/stdc++.h>
using namespace std;

class Node{
      public:
            int data;
            Node* next;
};

void add_node(Node** head_ref, int new_data){                //adding nodes to the list
      Node* p = new Node();
      p->data = new_data;
      p->next = *head_ref;
      *head_ref = p;
}

void delete_node(Node** head_ref, int del_val){
      Node* temp = *head_ref, *pre_node;

      if(temp!=NULL && temp->data ==del_val){                        //data of head matches w del_val
            *head_ref = temp->next;
            free(temp);
            return;
      }
      while(temp!=NULL&&temp->data!=del_val){                       //traverse the list to get the del_val node
            pre_node = temp;
            temp = temp->next;
      }
      if(temp==NULL)                                                //if not found return the list
            return;
      pre_node->next = temp->next;
      free(temp);

}


void print_data(Node* n){                                 //printing the list
      while(n!=NULL){
            cout<<n->data<<endl;
            n=n->next;
      }
}
int main(){                                                //driver function
      Node* head = NULL;

      add_node(&head, 8);
      add_node(&head, 0);
      add_node(&head, 3);
      add_node(&head, 5);
      add_node(&head, 4);
      cout<<"original list is: "<<endl;
      print_data(head);
      delete_node(&head, 3);
      cout<<"list after deletion"<<endl;
      print_data(head);
}
