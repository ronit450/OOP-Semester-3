#include<iostream>
using namespace std;

class TollBooth{
    int totalCars;
    double toll;

    public:
    TollBooth():totalCars(0), toll(0){}
    void payingCar(){
        totalCars++;
        toll+=50;
    }

    void nopayCar(){
        totalCars++;
    }

    void display() const{
        cout<<"Total cars passed: "<<totalCars<<endl;
        cout<<"Total toll collected: Rs. "<<toll<<endl;

    }
};


// provide LyariTollBooth class implementation, and write main function.
class LyariTollBooth : public TollBooth{
    int total_fine ;
    public: 
    LyariTollBooth(){
        TollBooth(); 
        total_fine = 0;
    }
    void payingCar(){
       TollBooth::payingCar();
       
    }

    void nopayCar(){
        TollBooth::nopayCar();
        total_fine = total_fine +500;
    }
    void display(){
        TollBooth::display();
        cout<<"Total fine collected: Rs. "<<total_fine<<endl;
    }
};

int main(){
    char input_character = 'z' ; 
    LyariTollBooth t1;
    while (input_character != 'q'){
        cin>> input_character;
        if (input_character == 'p'){
            t1.payingCar();
        }else if (input_character == 'n'){
            t1.nopayCar();
        }
    }
    t1.display();
    return 0;
}
