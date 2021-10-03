#include<iostream>
using namespace std;

class A{
public:
      static int x;
      A(){
            // x++;
      }
      ~A(){
            // x--;
      }

//      LAST STEP: So to count only heap object we'll overload the new operator, and comment above constructor and destructor

      void* operator new(size_t s){
            x++;
      }

      void operator delete(void*){
            // free(ptr);
            x--;
      }
};

int A::x=0;
int main(){
      // Stored in stack (local objects)
      A a, b;
      A c, d, e;

      // Dynamic allocated (STored in heap)
//      A* ptr = (A*)malloc(sizeof(A));     // it doesn't calls the constructor, only allocates the memory
      A* ptr = new A;
      A* ptr1 = new A;

     // free(ptr);        // It only destroys memory, but doesn't calls the destructor

      delete ptr;
      delete ptr;
      // ptr.~A();        //{ WHY CAN"T WE USE THIS?}

      cout<< A::x<<endl;
      // cout<< sizeof(A);


}
