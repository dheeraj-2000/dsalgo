/**
  Operator Overloading:
  Operator Overloading is a very essential element to perform the operations on 
  user-defined data types. By operator overloading we can modify the default 
  meaning to the operators like +, -, *, /, <=, etc. 
**/

class complex{
private:
 float r, i;
public:
 complex(float r, float i){
  this->r=r;
  this->i=i;
 }
 complex(){}
 void displaydata(){
  cout<<”real part = “<<r<<endl;
  cout<<”imaginary part = “<<i<<endl;
 }
 complex operator+(complex c){
  return complex(r+c.r, i+c.i);
 }
};
int main(){
complex a(2,3);
complex b(3,4);
complex c=a+b;
c.displaydata();
return 0;
}
