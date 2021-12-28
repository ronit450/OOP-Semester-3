#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main(){
    int temp = rand() % 2;
    switch(temp)
    {
         case 0:
            cout<<"It was very hard to run out of this trap but you made it!! You are Intelligent"<<endl;
            break;
        case 1:
            cout <<"The trap was well designed where you got a scar but you finally made it. Your survival Instinct are great!!!"<<endl;
        case 2:
            cout<<"There is trap inside a trap. Oh well you cleared the trap. well done!!!"<<endl;
    }

    return 0;
}