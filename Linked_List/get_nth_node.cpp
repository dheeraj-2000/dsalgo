#include<bits/stdc++.h>
#include <assert.h>
using namespace std;

class Node{
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

/*
void print_node(Node* n){
      while(n!=NULL){
            cout<< n->data<<endl;
            n=n->next;
      }
}
*/
/*/iterative approach
int getnth_ele(Node* head, int n){
      Node* temp = head;
      int count = 0;                                    //iterativeapproach
      while(temp != NULL){
            if(count == n)
                  return(temp->data);
            count++;
            temp = temp->next;
      }
      assert(0);

}*/


//recursive approach
int getnth_ele(Node* head, int n){
      int count =1;

      if(count==n)                                                   //recursive approach
            return head->data;

      return getnth_ele(head->next, n-1);
}



 int main() {
           Node* head = NULL;
            int n;

            add_node(&head, 8);
            add_node(&head, 7);
            add_node(&head, 3);
            add_node(&head, 4);
            add_node(&head, 9);
            //print_node(head);
            cout<<"enter the element to be printed: ";
            cin>>n;
            cout<<"element at nth posn is:"<<getnth_ele(head, n);


            // cout<<"gjh";
      return 0;
}
