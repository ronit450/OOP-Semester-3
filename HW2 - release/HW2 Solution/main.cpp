#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Structure to keep track of various locations
struct Point
{
    int x;
    int y;

    Point(int _x, int _y): x(_x), y(_y)
    {

    }
};
//Structure for the Player object
struct Player
{
    int food;
    int health;
    bool alive;
    int x;
    int y;
    bool win;
    bool enemy_win;
    Player()
    {
        food = 64;
        health = 10;
        alive = true;
        win = false;
        enemy_win = false;
    }
    void loseHealth()
    {
        if(health>0)
            health--;
        if(health==0)
            alive = false;
    }
    void gainHealth()
    {
        if(health<10)
            health++;
    }
};

typedef const int cint;         //Google typedef to see what this means
typedef const Point cPoint;


/* This was made for testing purpose to display the dungen. Feel free to remove the comment sign to check.
void displaying_dungen(char* dungeon_array, int width, int height){
    int counter = 0;
      for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            cout<<*(dungeon_array+ counter);
            counter++;
        }
        cout<<endl;
      }
}
*/

// Void function made if player gets into any trap 
void TrapStatements()
{
    int temp = rand() % 3;
    switch(temp)
    {
         case 0:
            cout<<"Not a good time to run into a trap. Be careful and try to come out"<<endl;
            break;
        case 1:
            cout <<"Carefull!!!  you may wak over those trapped bombs"<<endl;
            break;       
        case 2:
            break;
            cout<<"There was trap inside a trap. But,  Oh well you cleared the trap. well done!!!"<<endl;
    }
    // Case statements are used which will depend on random number generatet, stored in temp
}

void FoodStatements(Player& Player)
{
    // Food statements if player gets any food
    int temp = rand() % 3;
    // Random used as food are for 4 to 5 days.
    int days_for_food = rand() % 5 + 4;
    switch(temp)
    {
         case 0:
            cout<<"You have found Apples for "<< days_for_food<< " days. Good an apple a day keeps a doctor away"<<endl;
            break;
        case 1:
            cout <<"You have found oranges for "<< days_for_food<< " days. They will give you vitamin C"<<endl;
            break;       
        case 2:
            cout<<"Always see what you are eating. These were poisionous berries!!"<<endl;
            Player.alive = false;
            break;
            // if program gets into case 2 , player will eat poisonous food and will die and program will end.
    }
    
       
}

void HitStatements(Player &user_player)
{
    // function with 30% probablity that player will hit back
    int temp = rand() % 3;
    switch(temp)
    {
         case 0:
            cout<<"And here you have put a scar on his face and then five nuckkle shufle!!"<<endl;
            break;
        case 1:
            cout <<"And here You have given him super-man pucnch like Roman Reigns"<<endl;
            break;
        case 2:
        // if program puts it into case 2 winning statement will form and user will win. 
            cout<<"Bravoo !! Finally a great move which lead enemy down."<<endl;
            user_player.win = true;
            break;
    }
    
}

void GetHitStatements(Player &user_player)
{
    // Void function with 30% probablity that enemy will back
    int temp = rand() % 3;
    switch(temp)
    {
         case 0:
            cout<<"Be Careful It was a very near hit which could harm you. Try dodjing him!!"<<endl;
            break;
        case 1:
            cout <<"Oh no! You got a wound and You are bleeding heavily!! You have to be very Careful"<<endl;
            break;
        case 2:
        // case 2 statement if probablity falls into this enemy will beat player and player will die
            cout<<"Oh no! You fought bravely but I think the odds were in his favour. Better Luck next time."<<endl;
            user_player.alive = false;
            break;
    }
  
}
// Function which tells how much to reduce the with respect to each move
// If there is up move it will reduce width amount
// If there is right move it will return +1
// If there is left move it will return -1 
int choice_food_reducer(char choice, int width){
    if (choice == 'U'|| choice == 'u'){
        return  (width*-1);
    }else if (choice == 'D' || choice == 'd'){
        return width;
    }else if (choice == 'R'|| choice == 'r'){
        return 1;
    }else{
        return -1;
    }
}
void Combat(Player& player, int enemies)
{
    int random_number = 0;
    cout<<"Alert!!!! You have encountered "<<enemies<<" enemies. You have to be strong and make them on their knees"<<endl;
    // Loop for each enemy like if there are two enemies it will run for 2 times. 
    for (int i = 1; i<= enemies; i++){
        player.enemy_win = false;
        player.win = false;
        cout<<"Enemy "<<i<<endl;;
        // This will run until enemy or player win the match with respective probablity.
        while(player.enemy_win == false && player.win == false){
            random_number = (rand()% 10);
            if (random_number <=3){
                HitStatements(player);
            }else if (random_number < 4){
                GetHitStatements(player);
            }else{
                cout<<"You did'nt get git but you did'nt hit enemy as well. Try hitting him on his face before he could let you on your knees!!"<<endl;
            }
        }

    }
}
void object_placer(char* dungeon,cint width, cint height ){
    // Seperate function made for placing object with respective probability.
     for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            int probability = rand() % 10;
                if (probability == 2) {
                    int probability_for_placing_objects = rand() % (width*height);
                    if (probability_for_placing_objects>0 && probability_for_placing_objects <=15){
                        int placing_object = (rand() % ((width*height)+ (width + width +(height-2))));
                        *(dungeon+ placing_object) = 'E';
                        
                    }else if (probability_for_placing_objects > 15 && probability_for_placing_objects <=30){
                        int placing_object = (rand() % ((width*height)+(width+ height-2)));
                        *(dungeon+placing_object) = 'H';
                        
                    }else if (probability_for_placing_objects >30 && probability_for_placing_objects <=45){
                        int placing_object = (rand() % ((width*height)+(width+ height-2)));
                        *(dungeon+placing_object) = 'T';
                        
                    }else if (probability_for_placing_objects >45 && probability_for_placing_objects <=60){
                        int placing_object = (rand() % ((width*height)+(width+ height-2)));
                        *(dungeon +placing_object) = 'F';
                        
                    }else{
                        int placing_object = (rand() % ((width*height)+(width+ height-2)));
                        *(dungeon+placing_object) = 'W';
                    }
                }
        }
        // (upper bound is (width*height) which will make sure that object is placed within the dungen.)
        // (width + height - 2) which is lower bound which will eliminate the boundries point.
     }

}

void Traversal(char* dungeon, Point& startPoint, cPoint& exitPoint, cint width, cint height)
{
    Player user_player;
    char choice ;
    int food_reducer = 0;
    int temp_starting_point = 0;
    int start_point = ((startPoint.x * width) + startPoint.y);
    int exit_point =  ((exitPoint.x * width) + exitPoint.y);
    *(dungeon + start_point) = 'P';
    *(dungeon + exit_point) = 'X';
    object_placer(dungeon, width, height);
    while (user_player.alive == true){
        cout<<"Food remaining " <<user_player.food<< endl;
        cout<<"Health remaining "<<user_player.health <<endl;
        cout<<"Please tell us your valid move (U/R/L/D)"<<endl;
        cin>>choice;
        // If player inputs x program will terminate.
        while ((choice!='U' && choice != 'u' &&choice!='R' && choice!='r' &&choice!='L' &&choice!='l' &&choice!='D' &&choice!='d')){
            if (choice == 'x' || choice == 'X'){
                cout<<"You have chosen to end the game"<<endl;
                user_player.alive = false;
                break;
            }

            cout<<"Please Provide a Valid input"<<endl;
            cin>>choice;
        }
        user_player.food--;
        food_reducer = choice_food_reducer(choice, width);
        temp_starting_point = start_point + food_reducer;
        if (*(dungeon + temp_starting_point) == 'W'){
            cout<<"Be Careful there is a wall ahead!! You cant move through the wall and you lost one Food"<<endl;
        }else if (*(dungeon + temp_starting_point) == 'F'){
            cout<<"Congratulation You got the food"<<endl;
            FoodStatements(user_player);
            
            *(dungeon + start_point) = ' ';
            start_point = temp_starting_point;
            *(dungeon + start_point) = 'P';

        }else if (*(dungeon + temp_starting_point) == 'T'){
            user_player.loseHealth();
            TrapStatements();
            
            *(dungeon + start_point) = ' ';
            start_point = temp_starting_point;
            *(dungeon + start_point) = 'P';
            
        }else if (*(dungeon + temp_starting_point) == 'H'){
            cout<<"You have got Bandages and Health kit. Pick it up as it will help you to stay alive and fight enemy"<<endl;
            user_player.gainHealth();
            
            *(dungeon + start_point) = ' ';
            start_point = temp_starting_point;
            *(dungeon + start_point) = 'P';

        }else if (*(dungeon + temp_starting_point) == 'E'){
            int enemy = 2+ (rand()% (4-2+1));
            Combat(user_player, enemy);
            
            *(dungeon + start_point) = ' ';
            start_point = temp_starting_point;
            *(dungeon + start_point) = 'P';
        }else if (*(dungeon + temp_starting_point) == 'X'){
            cout<<"Congratulation!!! You Won. You used every technique and made out of the dungeon"<<endl;
            user_player.win = true;

        }
        else{
            *(dungeon + start_point) = ' ';
            start_point = temp_starting_point;
            *(dungeon + start_point) = 'P';
        }
        if (user_player.food == 0)
    {
        user_player.alive = false;
    }
        // displaying_dungen(dungeon, width, height);
   
    }
}
// Function which will create dungen array
char* CreateDungeon(int width, int height, Point& ref_startPoint, Point& ref_exitPoint)
{
   char* dungeon_display = new char[width*height];
   int count = 0;
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
           if ((i == 0 || i == (width -1))|| j==0 || j == (height-1) ){
               *(dungeon_display+count) = 'W';
               count++;
           }else{
               *(dungeon_display+count) = ' ';
               count++;
            
           }
       }
     
    }
    return dungeon_display;
   }
   
int validating_the_input(int validated_input){
  
   int temp = 0;
    while (validated_input <8){
        cout<<"The value must be greater than 8"<<endl;
        cin>>validated_input;
    }
    return validated_input;
}

int main()
{
    srand(time(0));

    int width = 0;
    int height = 0;
    bool validation = false;
    cout<<"Please tell the requred width for Dungen. Remember it should be more than or equal to  8"<<endl;
    cin>> width;
    width = validating_the_input(width);
    cout<<"Please tell the requred height for Dungen. Remember it should be more than or equal to  8"<<endl;
    cin>> height;
    height = validating_the_input(height);

    Point startPoint(2,1);
    Point exitPoint(7,6);

    char* dungeon = nullptr;

    dungeon = CreateDungeon(width, height, startPoint, exitPoint);
    
    Traversal(dungeon, startPoint, exitPoint, width, height);

    /*
    *   ADD YOUR CODE HERE IF REQUIRED
    */

    return 0;
}