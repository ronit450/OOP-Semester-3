#pragma once
#include "box.hpp"
#include <vector>
#include <fstream>
#include <time.h>

class Truck
{

    std::string driver;
    int petrol;
    int money;
    int fullMileage;
    int emptyMileage;
    Box box[10];

public:

// this is load function that will load the boxes into the truck. We are assuming the boxes to be 10 as
// the question says the bus is fully loaded.
    
    void load(int numBox){
        srand(0);
        for (int i=0; i < numBox; i++){
            box[i] = Box();
        }
    }

// default constructor
    
    Truck(){
        driver;
        petrol = 0;
        money = 0;
        fullMileage = 0;
        emptyMileage = 0;
        Box box[10];
    }

// overloaded constructor
    
    Truck(string name, int p,int m, int e, int f){
        driver = name;
        petrol = p;
        money = m;
        emptyMileage = e;
        fullMileage = f;
        Box box[10];
    }

// it will unload the truck and show dimensions for each box
    
    void unload(Truck t){
        for (int i=0; i < 10; i++){
        cout << "Box no. " << i +1 << ", ";
        t.box[i].showDimensions();
        
        }
    }

// it will calculate the cost of petrol for each truck
    
    float cost(){
        float cost = (50 - petrol) * 2.73;
        return cost;
    }

// it will check the cost for each truck, if they are able to full the tank or not
    
    void checkCost(vector<Truck>& t1,int i){
        if (cost() > money || (((60/emptyMileage)+ (60/fullMileage)) > 50)){
            t1.erase(t1.begin()+i);
        }
    }
//this function will update the truck information after it has completed its journey.
    
    void updateTruckinfo(){
        money -= cost();//(50-petrol) * 2.73;
        petrol = 50 - ((60/emptyMileage) + (60/fullMileage));
    }

// this function will add all the info of truck into .txt file.

    void print(ofstream& file){
        file << driver << endl;
        file << petrol << endl;
        file << money << endl;
        file << emptyMileage << endl;
        file << fullMileage << endl;

    }
};

