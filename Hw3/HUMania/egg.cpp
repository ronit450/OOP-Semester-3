#include "egg.hpp"
#include <vector>
using namespace std;

// icluding egg.hpp file so it can be used here

//Function to draw the object
void Egg::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    // Drop Function calling which will be called whenever new egg object is crated
    drop();
}

// Constructor to call and intitate the co-ordinates
Egg::Egg(){
    srcRect = {228,24,132,174};
    moverRect = {30, 40, 50, 60};
    // src coorinates from assets.png file, they have been found using spritecow.com
    // it will display egg on x = 30, y = 40 location, the size of egg is 50 width, 60 height
}
Egg::Egg(int x, int y){
    srcRect = {228,24,132,174};
    moverRect = {x, y, 50, 60};
    // src coorinates from assets.png file, they have been found using spritecow.com
    // it will display egg on x = 30, y = 40 location, the size of egg is 50 width, 60 height
}
void Egg::drop(){
    srcRect = {228,24,132,174};
    if (moverRect.y >500){
        //if egg touches the surface, it will break down and the co-ordinate will change
        srcRect = {207,244,231,186};
    }else{
        // If egg is not broken it will start coming down by the factor of 20
        moverRect.y += 20;
    }
}