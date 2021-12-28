#include<iostream>


using namespace std;
class Vehicle{
  string regNo;
  int no_of_wheels;
  public:
  Vehicle(string regNo, int no_of_wheels): no_of_wheels(no_of_wheels) ,regNo(regNo){}
    virtual void show(){
      cout<<" Reg. No.:"<<regNo<<", No. of wheels: "<<no_of_wheels<<endl;
  }
};
class Truck: public Vehicle{
    int maxWeight;
    public:
    Truck(string regNo, int no_of_wheels, int maxWeight): Vehicle(regNo, no_of_wheels), maxWeight(maxWeight){}
    
    void show(){
        
        cout<<"This is a Truck, Max Weight: "<<maxWeight;
        Vehicle::show();
    }
       
    
      
};

int main(){
    int n, weight, wheels;
    string reg;
    Vehicle *ptr;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>reg>>wheels>>weight;
        ptr = new Truck(reg, wheels, weight);

        //notic the following call is polymorphic, hence show function must be virtual in Vehicle class.
        ptr->show();

        
        delete ptr;
    }    
}