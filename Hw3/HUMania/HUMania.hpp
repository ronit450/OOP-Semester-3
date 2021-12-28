#include<SDL.h>
#include "pigeon.hpp"
#include "egg.hpp"
#include "nest.hpp"
#include "MyVector.cpp"
class HUMania{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;

    //Right now we're creating one pigeon, 
    // In the solution you have to create vectors of pigeons, eggs, and nests    
    MyVector<Pigeon>p_vector;
    MyVector<Egg> e_vector;
    MyVector<Nest> n_vector;

    public:
    HUMania(SDL_Renderer *, SDL_Texture *);
    // functions which will be used in Humania.cpp file
    void drawObjects(); 
    void createObject(int, int);
    
    
};