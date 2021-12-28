#include<iostream>
#include "HUMania.hpp"
#include <ctime>


void HUMania::drawObjects(){
    // call draw and animating functions of all the objects here with refrence to specified vector
    for(int count = 0; count < p_vector.size(); count ++){
        p_vector[count].draw(gRenderer,assets);
        p_vector[count].fly();
    }
    for(int count = 0; count < e_vector.size(); count ++){
        e_vector[count].draw(gRenderer,assets);
        // calling animated function together
        e_vector[count].drop();
    }
      for(int count = 0; count < n_vector.size(); count ++){
        n_vector[count].draw(gRenderer,assets);
        // calling wiggle function together with draw function 
        n_vector[count].wiggle();
    }

}

void HUMania::createObject(int x, int y){
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
    int random_number = 0;
    srand(time(0));
    random_number = rand() % 3 +1;
    // Making a static bool to know if there are no piegon availble on screen then practically there should 
    // not be any egg falling
    static bool piegon_present = false;

    //Switch statment to have a randomize number generating so that we can decide which object to create
    switch (random_number)
    {
    case 1:
    p_vector.push_back(Pigeon(x,y));
    piegon_present = true;
    break;
    case 2 :
    if (piegon_present != false){ 
        // Passing x and y value to know from where to start
        e_vector.push_back(Egg(x,y));
    }
    break;
    case 3:
    n_vector.push_back(Nest(x,y));
    break;
    }
    //Switch statements to push the objects into vectors. 


}
//Constructor of HuMania to define Sdl render and texture
HUMania::HUMania(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst){}
