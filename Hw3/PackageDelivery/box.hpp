#pragma once
#include<iostream>
using namespace std;

class Box
{
    int length;
    int width;
    int height;

public:
    
    Box(){

        length = (rand()%26)+5;
        width = (rand()%26)+5;
        height = (rand()%26)+5;
    }
    Box(int l, int w, int h){
        length = l;
        width = w;
        height = h;
    }
    int volume(){
        int v = length * width * height;
        return v;
    }

// while unloading it will display the dimension of each box belong to a truck

    void showDimensions(){
        cout << "L: " << length << "in" << ", " << "W: "  << width << "in" << ", " << "H: " << height << "in" << endl;
        cout << "volume: " << volume() << "in^2" << endl;
        cout << "-----------" << endl;
    }
};
