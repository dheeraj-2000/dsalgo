#include<iostream>
using namespace std;
class Stack{
    int data;
    Stack *next;
    Stack *top;
public:
    Stack(){
        top=nullptr;
    }
    void push(int);
    void pop();
    void print();
};

void Stack::push(int input){
    Stack *node=new Stack();
    node->data=input;
    node->next=nullptr;
    if(top==nullptr){
        top=node;
    }
    else{
        node->next=top;
        top=node;
    }

}

void Stack::pop(){
    if(top==nullptr){
        cout<<"Empty stack\n";
    }
    else{
        Stack *ptr=new Stack();
        ptr=top;
        cout<<"Deleted number is: "<<ptr->data<<"\n";
		top=top->next;
		delete(ptr);
    }
}

void Stack::print(){
    Stack *ptr=new Stack();
    ptr=top;
    if(ptr==nullptr){
        cout<<"Empty Stack\n";
    }
    while(ptr!=nullptr){
        cout<<ptr->data<<"\n";
        ptr=ptr->next;
    }
}

int main(){
    Stack object;
    int op=0;

    while(op!=4){
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Print\n";
        cout<<"4. End\n";
        cout<<"Enter operation to perform: ";
        cin>>op;
        cout<<"\n";
        switch(op){
        case 1:
            int input;
            cout<<"Enter number to push\n";
            cin>>input;
            object.push(input);
            cout<<"\n";
            break;
        case 2:
            object.pop();
            break;
            cout<<"\n";
        case 3:
            object.print();
            break;
            cout<<"\n";
        case 4:
            cout<<"Thank you";
            break;
            cout<<"\n";
        default:
            cout<<"Enter correct operation";

        }

    }
}


