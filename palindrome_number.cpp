#include<iostream>
using namespace std;
bool palindrome(int n){ 
    int rev=0;
    int n1=n;
    while(n!=0){
        int d=n%10;
        rev=rev*10+d;
        n/=10;
    }
    if(n1==rev){
        return true;
    }
    else return false;
}
int main(){
    int num;
    cout<<"Enter number :";
    cin>>num;
    
    if(palindrome(num)==true){
        cout<<num<<" IS PALINDROME";
    }
    else cout<<num<<" IS NOT PALINDROME" ;
    return 0;
}