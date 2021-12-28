#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
void print_yrs_array(int num_yrs, int yrs[]){
    int temp = 0;
    for (int counter = 0; counter < num_yrs-1; counter++){
            cout<< yrs[counter]<<", ";
            temp++;
        }
    
    cout<<yrs[temp];
}
void chronological_order(int num_yrs, int yrs[]){
    int temp = 0;
    for (int i = 0; i < num_yrs-1;i++){
        for (int j = i+1; j<num_yrs; j++ ){
            if (yrs[i] > yrs[j]){
                temp = yrs[i];
                yrs[i] = yrs[j];
                yrs[j] = temp;
            }
        }
    }
    print_yrs_array(num_yrs, yrs);
}
void input_years(int num_yrs , int yrs []){
    for (int counter = 0; counter< num_yrs; counter++){
        bool input_validation  = 0;
        cin>> yrs[counter];
        while (input_validation == 0){
            if ((yrs[counter])<0 && (yrs[counter])>9999 ){
                cout<<"Year can be between 0 and 9999!Try Again!"<<endl;
                cin>> yrs[counter];
            }else{
                input_validation = true;
            }
        }
    }
    print_yrs_array(num_yrs, yrs);    
}

int main(){
    int input_validation = 0;
    int number_of_inputs = 0;
    cin>> number_of_inputs;
    int initial_array [number_of_inputs];
    while (input_validation == 0){
        if (number_of_inputs<2){
            cout<<"Need at least 2 years to sort! Try again"<<endl;
            cin>> number_of_inputs;
        }else{
            input_validation = 1;
        }
    }
    cout<<"The initial array is: ";
    (input_years(number_of_inputs, initial_array));
    cout<<endl;
    cout<<"The sorted array is: "; 
    (chronological_order(number_of_inputs, initial_array));
}