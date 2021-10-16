// Problem link : https://codeforces.com/contest/791/problem/A

#include<stdio.h>
int main(){

	int a,b,c=0;
	
    scanf("%d %d",&a,&b);
    
    //Loop to add age
    while (a <= b){
        a = 3*a;
        b = 2*b;

        c=c+1;
    }
 
    printf("%d",c);
}
