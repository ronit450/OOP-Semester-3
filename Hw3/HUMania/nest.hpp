#include<SDL.h>

class Nest{
    // defining the Private attribute of class which defines the co-ordinate of Nest object
    SDL_Rect srcRect, moverRect;
    public:
    void draw(SDL_Renderer*, SDL_Texture* assets);
    // Constructor of Nest 
    Nest();
    // Fucntion of have a wiggling effect
    void wiggle();
    // Overloaded constructor to know the location for Movereact x and y co-ordinates
    Nest(int, int);
};