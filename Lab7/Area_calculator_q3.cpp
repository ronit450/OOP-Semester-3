#include<iostream>

using namespace std;

struct Distance{
    int feet, inches;
};
class Area{
    Distance length; Distance Width;
    public:
    Area (Distance Len , Distance Wid){
        length.feet = Len.feet;
        length.inches = Len.inches;
        Width.feet = Wid.feet;
        Width.inches = Wid.inches;        
    }
    Area(){}
    operator double(){
        return ((length.feet + length.inches/ 12.0)* (Width.feet + Width.inches/12.0));
    }
};
int main(){
    double ft1, ft2, in1, in2;
    cin>>ft1>>in1>>ft2>>in2;
    Area area1 = {{ft1, in1}, {ft2,in2}};
    
    double decimalArea = area1; // overload the double operator to convert area object into decimal value.
    cout<<"Area is: "<< decimalArea <<"sq feet"<<endl;

}