#include <iostream>
using namespace std;

int string_length (char temp_array[]){
    int length ;
    for (int counter=0; counter<1000; counter++){
        if (temp_array[counter] == '\0'){
            break;
        }else{
            length++;
        }
    }
    cout<<length;
    return 0;
}



int main(){
    char temp_array[1000];
    cin.get(temp_array , 1000);
    string_length(temp_array);
}