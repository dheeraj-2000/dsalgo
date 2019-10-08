#include<bits/stdc++.h>
using namespace std;

class Node{
public:
      int data;
      Node* next;
};

int add_node(Node** head_ref, int new_data){                  //adding at begining
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

bool isPalllindrome(Node* head){
      Node* temp = head;

      stack <int> s;

      while(temp!=NULL){
            s.push(temp->data);
            temp = temp->next;
      }

      while(head!= NULL){
            int check = s.top();
            s.pop();

            if(head->data!= check)
                  return false;
            head = head->next;
      }
      return true;
}


int main() {
          Node* head = NULL;
           int n;

          /* add_node(&head, 8);
           add_node(&head, 7);
           add_node(&head, 3);
           add_node(&head, 7);
           add_node(&head, 8);*/
           cin>>n;
           for (int i=0; i<n; i++){
                 cin>>i;
                 add_node(&head, i);
          }

           int res = isPalllindrome(head);
           if(res== 1)
              cout<<"is Palllindrome";
           else
             cout<<"Not Palllindrome";
}
