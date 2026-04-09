#include <iostream>
using namespace std;

// operator overloading



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
void getData(){
    cout<<"Enter feet and inch: ";
    cin>>feet>>inch;
}
void display(){
    cout<<"Feet: "<<feet<<" Inch: "<<inch;
}
Distance Add(Distance d2){
    Distance d;
    d.feet=feet+d2.feet;
    d.inch=inch+d2.inch;
    if(d.inch>=12){
        d.feet++;
        d.inch=d.inch-12;
    }
    return d;
}
};
int main(){
    Distance d1,d2(10,5.5),d3;
    d1.getData();
    d3=d1.Add(d2);
    d1.display();
    d2.display();
    d3.display();   
}