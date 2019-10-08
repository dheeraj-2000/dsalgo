#include<bits/stdc++.h>
using namespace std;
class Node{
public:
      int data;
      Node* next;
      Node(int val, Node* next) : data(val), next(next){}
};


void add_node(Node** head_ref, int new_data){                    //adding nodes
      /*Node* new_node = new Node;
      new_node->data = new_data;
      new_node->next = *head_ref;
      *head_ref = new_node;*/
       (*head_ref) = new Node(new_data, *head_ref);
}

void remove_duplicate(Node* p){                            //removing duplicates
      Node *temp1 = p;
      Node  *temp2, *dup_node;
      while(temp1!=NULL && temp1->next!=NULL){                //3 6 3 7 8
            temp2 = temp1;
            while(temp2->next!=NULL){
                  if(temp1->data == temp2->next->data){
                        dup_node=temp2->next;
                        temp2->next = temp2->next->next;
                        delete(dup_node);
                  }
                  else temp2 = temp2->next;
            }
            temp1 = temp1->next;
      }
}



int print_node(Node* n){
  while(n!=NULL){
    cout<<n->data<<endl;        //printing nodes
    n = n->next;
  }
}

int main(){                                             //driver function
      Node* head = NULL;
      /*int n;
      cin>>n;
      for(int i=0; i<n; i++){
            cin>>i;
            add_node(&head, i);
      }*/
      add_node(&head, 8);
      add_node(&head, 7);
      add_node(&head, 3);
      add_node(&head, 3);
      add_node(&head, 3);
      cout<<"Linked list before removing duplicates"<<endl;
      print_node(head);
      remove_duplicate(head);
      cout<<"Linked list after removing duplicate"<<endl;
      print_node(head);

}
