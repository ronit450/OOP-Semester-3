#include "truck.hpp"
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

class TruckDelivery{

    vector<Truck> trucks;
   
int counter = 0;

public:

//this function will read all the information from the drivers.txt file and populate the vector.
    
    void loadTrucks(ifstream& file){
        string line;
        Truck t1;
        string name;
        int p,m,e,f;                // variable are created so it will populate the truck object. 
        int counter = 0;            // counter for keeping track of reading the line
        file.open("Drivers.txt");
        while (getline(file,line)){
            if (counter % 5 == 0){
                name = line;
            }
            else if (counter % 5 == 1){
                p = stoi(line);
            }
            else if (counter % 5 == 2){
                m = stoi(line);
            } 
            else if (counter % 5 == 3){
                e = stoi(line);
            }
            else if (counter % 5 == 4){
                f = stoi(line);
                t1 = {name,p,m,e,f};
                trucks.push_back(t1);
            }
            counter += 1;
        }
    }

    // this function will calculate the cost of the petrol. If it does not meet its price
    // requirement, then it will erase that truck from vector.

    void calculateCost(){
        for (int i=0; i < trucks.size(); i++){
            trucks[i].checkCost(trucks,i);
        }
    }
    
    // this function will update the truck information after it has completed the journey.
    void makeJourney(){
        for (int i=0; i < trucks.size(); i++){
            trucks[i].updateTruckinfo();
        }
    }

    // this function will unload the trucks. show the boxes dimensions and update the trip.txt file.

    void unloadTrucks(){
        ofstream myfile("Trip.txt");
        for (int i =0; i < trucks.size(); i++){
            trucks[i].print(myfile);
            cout << "Truck no. " << i +1 << endl;
            cout << "----o----o----" << endl;
            trucks[i].unload(trucks[i]);
            cout << endl;
            
        }
    }
};
