#include <iostream>
using namespace std;
int main(){
    int c,amt;
    cout<<"Enter amount: ";
    cin>>amt;
    int notes[]={500,200,100,50,20,10,5,2,1};
    for(int i=0;i<9; i++){
        c = amt / notes[i];
        if(c!= 0){
            cout << c <<" notes of "<<notes[i]<<"\n";
            amt = amt % notes[i];
        }
    }}