#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "truck.hpp"
#include "box.hpp"
#include "truckDelivery.hpp"
#include <fstream>
#include <time.h>

using namespace std;

int main()
{   
    srand(time(0));

    ifstream file;
    file.open("Driver.txt");
    TruckDelivery delivery;
    delivery.loadTrucks(file);
    delivery.calculateCost();
    delivery.makeJourney();
    delivery.unloadTrucks();
    return 0;
}
