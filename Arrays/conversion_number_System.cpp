//debug this
//binary to decimal
//octal to decimal
//hexadecimal to decimal
//reverse of all
#include<iostream>
#include<math.h>
using namespace std;
int max_power_division(int m,int n){
    // m is no. n is divide
    int i=0;
    int power=n;
    while(m>power){
        power=pow(n,i);
        i++;
    }
    i--;
    return m/power;
}
int conversion(int from,int to,int value){
    int final =0;
    while(value>=10){
        final=final*10 + (value/max_power_division(value,to));
        value=value/10;
    }
    return final;
}
int main(){
    int hexa = conversion(10,8,58);
    cout<<hexa;
}