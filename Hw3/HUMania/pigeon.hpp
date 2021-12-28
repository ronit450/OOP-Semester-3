#include<SDL.h>

class Pigeon{
    // defining the Private attribute of class which defines the co-ordinate of Nest object
SDL_Rect srcRect, moverRect;
public:
    // add the fly function here as well.
    void draw(SDL_Renderer*, SDL_Texture* assets);
    Pigeon(); // may add other overloaded constructors here... 

    // Fly function to have a animation of piegon
    void fly();
    // Overloaded constructor to know the location for Movereact x and y co-ordinates
    Pigeon(int, int);
};
