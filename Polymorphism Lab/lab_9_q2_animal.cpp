#include<iostream>
using namespace std;
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <sstream>

class Animal{
    string name;
    string sound;
    public:
    Animal(string name, string sound): name(name), sound(sound){
    }
    string getname(){
        return name;
    }
    string getsound(){
        return sound;
    }
    virtual void make_sound() = 0;
};

class Cat:public Animal{
    string action = "purr";
    public:
    Cat(string name, string sound):Animal(name, sound){}
    Cat(string name):Animal(name, "Meow"){}
    void make_sound(){
        cout<<Animal::getname()<<" "<<action<<": "<<Animal::getsound()<<"!"<<endl;
    }
    
};
class Cow:public Animal{
    string action = "moo";
  public:
    Cow(string name, string sound):Animal(name, sound){}
    Cow(string name):Animal(name, "Moo"){}
    void make_sound(){
        cout<<Animal::getname()<<" "<<action<<": "<<Animal::getsound()<<"!"<<endl;
    }
};
class Dog:public Animal{
    string action = "barks";
    public:
    Dog(string name, string sound):Animal(name, sound){}
    Dog(string name):Animal(name, "Woof"){}
    void make_sound(){
        cout<<Animal::getname()<<" "<<action<<":"<<Animal::getsound()<<"!"<<endl;
    }
};

class Duck:public Animal{
    string action = "quack";
    public:
    Duck(string name, string sound):Animal(name, sound){}
    Duck(string name):Animal(name, "Quack"){}
    void make_sound(){
        cout<<Animal::getname()<<" "<<action<<": "<<Animal::getsound()<<"!"<<endl;
    }
};

class Horse:public Animal{
    string action = "nickers";
    public:
    Horse(string name, string sound):Animal(name, sound){}
    Horse(string name):Animal(name, "Neigh"){}
    void make_sound(){
        cout<<Animal::getname()<<" "<<action<<": "<<Animal::getsound()<<"!"<<endl;
    }
};

class Pig:public Animal{
    string action = "snort";
    public:
    Pig(string name, string sound):Animal(name, sound){}
    Pig(string name):Animal(name, "Oink"){}
    void make_sound(){
        cout<<Animal::getname()<<" "<<action<<": "<<Animal::getsound()<<"!"<<endl;
    }
};




int main(){
    int no_of_inputs = 0;
    int num_of_animal = 0;
    string name_of_animal = "";
    string sound_of_animal = "";
    cin>>no_of_inputs;
    Animal **ptr = new Animal* [no_of_inputs];
    for(int count = 0; count <no_of_inputs; count++){
        
        cin>>num_of_animal;
        cin>>name_of_animal;
        getline(cin,sound_of_animal);
        if ((num_of_animal == 1) && sound_of_animal!= ""){
            ptr[count] = new Cat(name_of_animal, sound_of_animal);
            
        }else if ((num_of_animal == 1) && sound_of_animal== ""){
            ptr[count] = new Cat(name_of_animal);
            
        }else if(num_of_animal ==2&& sound_of_animal!= ""){
            ptr[count] = new Cow(name_of_animal, sound_of_animal);
            
        }else if ((num_of_animal == 2) && sound_of_animal== ""){
            ptr[count] = new Cow(name_of_animal);
            
        }else if (num_of_animal == 3&& sound_of_animal!= ""){
            ptr[count] = new Dog(name_of_animal, sound_of_animal);
            
        }else if (num_of_animal == 3 && sound_of_animal== ""){
            ptr[count] = new Dog(name_of_animal);
            
        }else if (num_of_animal == 4&& sound_of_animal!= ""){
            ptr[count] = new Duck(name_of_animal, sound_of_animal);
            
        }else if (num_of_animal == 4 && sound_of_animal== ""){
            ptr[count] = new Duck(name_of_animal);
        
         }else if (num_of_animal == 5&& sound_of_animal!= ""){
            ptr[count] = new Horse(name_of_animal, sound_of_animal);
            
        }else if (num_of_animal == 5 && sound_of_animal== ""){
            ptr[count] = new Horse(name_of_animal);
            
         }else if (num_of_animal == 6&& sound_of_animal!= ""){
            ptr[count] = new Pig(name_of_animal, sound_of_animal);
            
        }else if (num_of_animal == 6 && sound_of_animal== ""){
            ptr[count] = new Pig(name_of_animal);
        }
    }
    int inputs_to_show = 0;
    int temp = inputs_to_show;
    cin>>inputs_to_show;
    while(inputs_to_show!= temp){
        ptr[inputs_to_show-1]->make_sound();
        temp = inputs_to_show;
        cin>>inputs_to_show;
    }
    
  
    return 0;
    }