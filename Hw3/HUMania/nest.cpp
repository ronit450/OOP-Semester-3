#include "nest.hpp"
#include <vector>
// icluding nest.hpp file so it can be used here

using namespace std;
int wiggling_effect = 0;
//Variable to Create a wiggling effect
void Nest::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    wiggle();
}

Nest::Nest(){
    srcRect = {484,0,156,145};
    // src coorinates from assets.png file, they have been found using spritecow.com
    // it will display nest on x = 534, y = 340 location, the size of nest is 50 width, 60 height
    moverRect = {534, 340, 50, 60};
}
Nest::Nest(int x, int y){
    srcRect = {484,0,156,145};
    // src coorinates from assets.png file, they have been found using spritecow.com
    // it will display nest on x = 534, y = 340 location, the size of nest is 50 width, 60 height
    moverRect = {x, y, 50, 60};
}
void Nest::wiggle(){
    if (wiggling_effect == 0){
        srcRect = {484,0,156,145};
        wiggling_effect +=1;
    }else if (wiggling_effect == 1){
        srcRect = {489,171,141,99};
        wiggling_effect +=1;
    }else {
        srcRect = {494,308,144,107};
        // it will reset the value to start the effect again
        wiggling_effect =0;
    }
    //choosing a Global Variable that will check the condition and change the src co-ordinates of assets picture.

}