//function overloading
#include <iostream>
using namespace std;
int sub(int a, int b){
    return a-b;
}
float sub(float a, float b){
    return a-b;
}
int main(){
    cout<<"Difference is: "<<sub(10.5f,20.5f)<<endl;
    return 0;
}