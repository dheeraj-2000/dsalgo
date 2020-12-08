#include<iostream>
using namespace std;

class SocialNetworking{
private:

public:
      virtual void secret() {};
};

class Facebook : public SocialNetworking{
private:
      string fbPassword;
      void secret(){
            cout<<"The Facebook Password: "<<fbPassword<<endl;
            cout<<"It's risky, but its fine to print here as it's private function"<<endl;
      }
public:
      Facebook(string pswd){
            fbPassword = pswd;
      }
};

int main(){
      Facebook text{"Dheeraj@fb"};
      // text.secret();                   // If we do this, than we'll get an error as, error: ‘void Facebook::secret()’ is private within this context
      SocialNetworking* ptr = &text;   // Pointer of base class is pointed to the object of derived class
      ptr->secret();

}
