#include<bits/stdc++.h>
using namespace std;

class Node {                   //defining a node
public:
  int data;
  Node* next;
};


int printdata(Node* n){
  while(n!=NULL){
    cout<<n->data<<endl;        //printing nodes
    n = n->next;
  }
}

int main(){
  /*  Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;*/

    head = new Node();             //adding nodes
    second = new Node();
    third = new Node();

    head->data =4;               //data of nodes
    head->next = second;
    second->data = 5;
    second->next = third;
    third->data = 9;
    third->next = NULL;

    printdata(head);
}
