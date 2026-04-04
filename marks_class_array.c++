// class marks storing marks of physics,chemistry and maths for 50 students
# include <iostream>
using namespace std;
class marks{
    private:
    int phy;
    int chem;
    int math;
public:marks(){
    phy=0;
    chem=0;
    math=0;
}
marks(int p, int c, int m){
    phy=p;
    chem=c;
    math=m;
}
void getData(){
    cout<<"Enter marks of physics, chemistry and maths: ";
    cin>>phy>>chem>>math;
}
void display(){
    cout<<"Physics: "<<phy<<" Chemistry: "<<chem<<" Maths: "<<math;
}
};

int main(){
    int n=10;
    marks m[n];
    for(int i=0;i<n;i++){
        m[i].getData();
    }
    for(int i=0;i<n;i++){
        m[i].display();
        cout<<endl;
    }
}