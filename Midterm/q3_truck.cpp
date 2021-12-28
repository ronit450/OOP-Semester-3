#include<iostream>
using namespace std;

class Box{
  int length; int width; int height;
  public:
  Box():length(3), width(2), height(3){}
  int calculateVolume(){
      return (length * width * height);
  }  
  
};

class Truck{
  Box* boxes;
  string registrationNo;
  int totalBoxesVolume;
  int nBoxes; int maxLoadCapacity;
  bool canMakeJourney;
  public:
  Truck(){
      cin>>registrationNo;
      cin>> maxLoadCapacity;
      cin>>nBoxes;
      totalBoxesVolume = 0;
      canMakeJourney = false;
      boxes = new Box[nBoxes];
      
      
  }
  void validate(){
      int temp;
      for (int count = 0; count < nBoxes; count++){
          temp = 
          totalBoxesVolume += boxes->calculateVolume();
      }
      if (totalBoxesVolume <= maxLoadCapacity){
          canMakeJourney = true;
      }
  }
  friend ostream& operator <<(ostream &out, Truck &t1){
      string journey_possible ;
      if (t1.canMakeJourney == false){
          journey_possible = "It can not make the journey successfully.";
      }else{
          journey_possible = "It can make the journey successfully.";
      }
      out<<"Truck No. "<<t1.registrationNo<<" has maximum loading capacity of "<<t1.maxLoadCapacity<<" m3. It carries "<<t1.nBoxes<<" boxes with total dimension of "<<t1.totalBoxesVolume<<" m3. "<<journey_possible<<endl;
      return out;
  }
};

int main(){
    int n;
    cin>>n;

    Truck trucks[n];

    for(int i=0;i<n;i++){
        trucks[i].validate();
        cout<<trucks[i];
    }
    return 0;
}

// Sample output messages:
// Truck No. AM2045 has maximum loading capacity of 100 m3. It carries 20 boxes with total dimension of 360 m3. It can not make the journey successfully.
// Truck No. HA3987 has maximum loading capacity of 300 m3. It carries 5 boxes with total dimension of 90 m3. It can make the journey successfully.


