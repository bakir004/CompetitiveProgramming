// STATUS: zavrsen, rjesenje nije moje
// IZVOR: KTSS-2016

#include <iostream> 
#include <cmath> 
#include <algorithm> 
#include <stdlib.h> 

using namespace std; 

int main() 
{ 
    int n; 
    int a; 
    int b; 
    cin>>n; 
    while(n>0) { 
        a=1; 
        while(a*a<n) { 
            a++; 
        } 
        b=a*a-n; 
        if(b==0) { 
            if(a%2==0) {
                cout<<a<<" "<<"1"<<endl;
            } else { 
                cout<<"1"<<" "<<a<<endl;
            } 
        } else if(b<a) { 
            if(a%2==0) {
                cout<<a<<" "<<1+b<<endl;
            } else {
                cout<<1+b<<" "<<a<<endl;
            } 
        } else if(b>=a) { 
            if(a%2==0) {
                cout<<a+a-b-1<<" "<<a<<endl;
            } else {
                cout<<a<<" "<<a+a-b-1<<endl;
            } 
        } 
        cin>>n; 
    } 
    return 0; 
}