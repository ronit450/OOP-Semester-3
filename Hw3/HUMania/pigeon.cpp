#include "pigeon.hpp"
// pigeon implementation will go here.
#include <vector>
using namespace std;
int count = 0;
void Pigeon::draw(SDL_Renderer* gRenderer, SDL_Texture* assets){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
    fly();
    }

Pigeon::Pigeon(){
    srcRect = {7,15,155,102};
    // src coorinates from assets.png file, they have been found using spritecow.com
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {30, 40, 50, 60};
}
Pigeon::Pigeon(int x, int y){
    srcRect = {7,15,155,102};
    // src coorinates from assets.png file, they have been found using spritecow.com
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {x, y, 50, 60};
}
void Pigeon ::fly(){
    if (count == 0){
        //setting up the count 1 when the assests of piegon is as co-ordinated. 
        srcRect = {7,15,155,102};
        count += 1;
    }else if (count == 1){
        //setting up the count 2 when the assests of piegon is as co-ordinated. 
        srcRect = {0,164,153,83};
        count += 1;
    }else{
        //setting up the count 0 when the assests of piegon is as co-ordinated. 
        srcRect = {2,288,159,123};
        // setting up the count =0 to create a sort of loop
        count = 0;
    }
    moverRect.x+=15; // moves the pigeon one pixel towards right, should it be in fly function??
    if (moverRect.x >= 990){
        moverRect.x = 30;
    }
}