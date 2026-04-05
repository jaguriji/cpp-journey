#include<iostream>
using namespace std;
class Distance{
    private:
    int feet;
    float inch;
public:Distance(){
    feet=0;
    inch=0.0;
}
Distance(int f, float i){
    feet=f;
    inch=i;
}
Distance operator+(Distance d2){
    Distance d;
    d.feet=feet+d2.feet;
    d.inch=inch+d2.inch;
    if(d.inch>=12){
        d.feet++;
        d.inch=d.inch-12;
    }
    return d;
}
void getData(){
    cout<<"Enter feet and inch: ";
    cin>>feet>>inch;
}
void display(){
    cout<<"Feet: "<<feet<<" Inch: "<<inch<<endl;
}
};
int main(){
    Distance d1,d2(10,5.5),d3(6,7),d4;
    d1.getData();
    d3=d1+d2;
    d1.display();
    d2.display();
    d3.display();
    d4=d1+d2+d3;
    d4.display();
}