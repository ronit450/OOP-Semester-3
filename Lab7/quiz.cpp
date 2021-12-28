#include<iostream>
#include<numeric>
using namespace std;
struct Fraction{
    int num, denom;
};
class FractionOperations{
    Fraction frac1;
    Fraction frac2;
    public:
  FractionOperations(Fraction f, Fraction f1){
      frac1.num = f.num;
      frac1.denom = f.denom;
      frac2.num = f1.num;
      frac2.denom = f1.denom;
  }
  FractionOperations(){
  }
  void simplification(Fraction &result){
      for (int count = result.denom; count >=2; count--){
          if ((result.num % count == 0) & (result.denom % count == 0)){
              result.num = result.num/count;
              result.denom = result.denom/count;
          }   
      }
  }
  void add(){
      Fraction result;
      result.num = ((frac1.num * frac2.denom)+(frac2.denom * frac1.num));
      result.denom = (frac1.denom * frac2.denom);
      cout<<"Result of addition is: "<<result.num<<"/"<<result.denom<<endl;
  }
  void multiply(){
      Fraction result;
      result.num = (frac1.num * frac2.num);
      result.denom = (frac1.denom * frac2.denom);
      cout<<"Result of multiplication is: "<<result.num<<"/"<<result.denom<<endl;
  }  
};



int main(){
    Fraction a, b;
    cin>>a.num>>a.denom>>b.num>>b.denom;
    FractionOperations f1(a, b);
    f1.add(); //calculates a+b and prints the result
    f1.multiply(); //calculates a*b and prints the result
    return 0;
}