#include <iostream>
using namespace std;
int main(){
    int x,y;
    cout<<"Enter co-ordinates"<<endl;
    cin>>x>>y;
    if(x>0)
    {
        if(y>0) cout<<"First Quadrant";
        else cout<<"Fourth Quadrant";
    }
    else{
        if(y>0) cout<<"Second Quadrant";
        else cout<<"Third Quadrant";
    }
}