#include<iostream>

using namespace std;

class default_constructor {

    public: default_constructor() {
        cout << "This is a default constructor";
    }

};

int main() {
    default_constructor d;
}