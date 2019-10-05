#include<bits/stdc++.h>
using namespace std;

class Node {                   //defining a node
public:
  int data;
  Node* next;
};

int add_begin(Node** head_ref, int new_data){                  //adding at begining
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int add_between(Node* pre_node, int new_data){                 //adding node in between
  if(pre_node == NULL)
    cout<<"given node can't be the last ndoe"<<endl;
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = pre_node->next;
  pre_node->next = new_node;
}

/*int add_last(Node** head_ref, int new_data){                     //adding node at the end
  if(*head_ref == NULL){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
  Node* last = *head_ref;}
  //new_node->data = new_data;
  // /new_node->next = NULL;


 else{
   Node* p = *head_ref;
   while(p!=NULL){
     if(p->next=NULL){
       Node*last = new Node();

       last->data = new_data;
       last->next = NULL;
       p->next = NULL;
       break;
     }
      p=p->next;
    }
  }
}*/

void add_last(Node** head_ref, int new_data){
    Node* new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL){                        //check whether the list is empty
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)                      //if not empty traverse to the last 
        last = last->next;

    last->next = new_node;
    return;
}

int printdata(Node*  node){                                        //printing data
  while (node!=NULL) {
    cout<<node->data<<endl;
    node=node->next;
  }


}

int main(){                                                       //driver function
  Node* head = NULL;

   add_last(&head, 6);
   add_begin(&head, 7);
   add_begin(&head, 1);

   add_last(&head, 4);

   add_between(head->next->next, 8);
printdata(head);

}
