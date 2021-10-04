#include<iostream>
using namespace std;
class node{
public:
int data;
node* link;
node(int value){
data=value;
link=NULL;
}
};
class queue{
public:
node* last;
int length=0;
void push(node* &head,int val){
node* n = new node(val);
if(length==0){
head=n;
last=n;
}
else{
last->link=n;
last=n;
}
length++;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"-->";
head=head->link;
    }
    cout<<"NULL\n";
}
void DELETE(node* &head){
    node* temp=head;
    head=temp->link;
    delete(head);
}
void peek(node* head){
    cout<<"The first object is "<<head->data;
}
};
int main()
{
node* head=NULL;
 queue q;
q.push(head,2);
q.push(head,5);
q.push(head,3);
q.push(head,4);
q.push(head,6);
q.display(head);
q.DELETE(head);
q.display(head);
q.DELETE(head);
q.display(head);
q.peek(head);
 return 0;
}
