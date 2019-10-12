#include<bits/stdc++.h>
using  namespace std;
class Node{
 public:
       int data;
       Node* next;
};

void reverse_list(Node** p){
      Node* curr = *p;
      Node *prev = NULL, *next=NULL;
      while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
      }
      *p = prev;
}

void add_node(Node** head_ref, int new_data){
      if(*head_ref == NULL){
      Node* new_node  = new Node();
      new_node->data =  new_data;
      new_node->next = NULL;
      *head_ref = new_node;}

      else

      {
            Node* p= *head_ref;
             while(p->next!=NULL){
                        p=p->next;}
            Node* new_node = new Node();
            new_node->data = new_data;
            p->next = new_node;
            new_node->next = NULL;
      }
}

int print_node(Node* n){
      while(n!=NULL){
            cout<<n->data<<endl;
            n=n->next;
      }
}

int main(){
      Node* head = NULL;
      int n;
      cin>>n;
      int l;
      for(int i=0; i<n; i++){
            cin>>l;
            add_node(&head, l);
      }
      /*add_node(&head, 8);
      add_node(&head, 7);
      add_node(&head, 3);
      add_node(&head, 4);
      add_node(&head, 9);*/
      cout<<"Original Linked list is: "<<endl;
      print_node(head);
    reverse_list(&head);
      cout<<"list after rotation is: "<<endl;
      print_node(head);

}
