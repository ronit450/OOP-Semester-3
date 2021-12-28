#include<iostream>

using namespace std;
class Complex{
    double real =0;
    double imag=0;
    public:
    Complex(double real, double imag):real(real), imag(imag){
    }
    Complex(){}
    Complex operator + (Complex c2){
        return Complex {real+c2.real, imag+c2.imag};
    }
    Complex operator +(double value){
        return Complex {real + value ,imag};
    }
    Complex operator - (Complex c2){
        return Complex {real-c2.real, imag-c2.imag};
    }
    Complex operator -(double value){
        return Complex {real - value ,imag};
    }
    Complex operator *(Complex c2){
        return Complex {(real * c2.real)+ ((imag * c2.imag)*-1), (real *c2.imag) + (imag * c2.real)};
    }
    Complex operator *(double value){
        return Complex {(real*value), (imag * value)};
    }
    friend ostream& operator <<(ostream &out, Complex &c1){
         if (c1.imag < 0){
         out<<c1.real<<c1.imag<<"i";
    }else{
        out<<c1.real<<"+"<<c1.imag<<"i";
    }
    return out;
    }
    friend istream & operator >>(istream &input , Complex &c1){
        input>> c1.real >> c1.imag;
        return input;
    }
};


int main(){
   Complex c1, c2;
    
    cin>>c1; //extraction operator is overloaded
    cin>>c2;

    double d1;
    cin>>d1;
    
    Complex result;
    //showing the numbers:
    cout<<"c1: "<< c1 <<endl; // insertion operator is overloaded
    cout<<"c2: "<< c2 <<endl; 
    cout<<"d1: "<< d1 <<endl;

    // Check the opertions where both operands are complex
    result = c1 + c2; 
    cout<<"c1+c2: "<<result<<endl;
    
    
    result = c1 - c2; 
    cout<<"c1-c2: "<< result <<endl;
    
    result = c1 * c2; 
    cout<<"c1*c2: "<< result <<endl;
    
    // Check the opertions where one operator is complex, other is double

    result = c1 + d1; 
    cout<<"c1+d1: "<< result <<endl;
    
    
    result = c1 - d1; 
    cout<<"c1-d1: "<< result <<endl;
    
    result = c1 * d1; 
    cout<<"c1*d1: "<< result <<endl;
}