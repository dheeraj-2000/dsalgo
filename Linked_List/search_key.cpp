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

bool search_key(Node* head, int key){
      Node* temp = head;
      while(temp!=NULL){

            if(temp->data==key)
                  return true;
            temp = temp->next;
      }
      return false;
}

int main(){
      Node* head = NULL;
      int key;
      add_node(&head, 8);
      add_node(&head, 2);
      add_node(&head, 9);
      add_node(&head, 5);
      cout<<"enter the key you want to search: ";
      cin>>key;
      search_key(head, key) ? cout<<"yes" : cout<<"not present";
      return 0;

}
