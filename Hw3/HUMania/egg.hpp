#include<SDL.h>

class Egg{
    // defining the Private attribute of class which defines the co-ordinate of Nest object
    SDL_Rect srcRect, moverRect;
    public:
    // add the fly function here as well.
    void draw(SDL_Renderer*, SDL_Texture* assets);
    Egg();
    Egg(int, int);
    // Overloaded constructor to know the location for Movereact x and y co-ordinates
    void drop();

};