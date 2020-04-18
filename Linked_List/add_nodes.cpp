#include<bits/stdc++.h>
using namespace std;
class Node {                   //defining a node
public:
  int data;
  Node* next;
};

int add_node(Node** head_ref, int new_data){                  //adding a node at begining
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int get_sum(Node*  node){
      int sum =0;                                       //printing data
  while (node!=NULL) {
        sum += node->data;
    //cout<<node->data<<endl;
    node=node->next;
  }
  cout<<"sum of the nodes are: "<< sum;
  //return sum;
}



int main(){                                                 //Driver Function
      Node* head = NULL;                                    //intilizing head as Null value
      int n,l;
      cin>>n;
      while(n--){
            cin>>l;
            add_node(&head, l);}
      //cout<<"sum of the nodes are: ";
      get_sum(head);
}
