#include <iostream>
using namespace std;

int string_length (char temp_array[]){
    int temp;
    int counter_for_result_array = 0;
    char result_array [1000];
    for (int counter=0; counter<1000; counter++){
        if (temp_array[counter] == '\0'){
            break;
        }else if (temp_array[counter]=='a' || temp_array[counter] == 'c' ||temp_array[counter] == 'g' || temp_array[counter] == 't'){
          temp = (int(temp_array[counter]))-32;
          result_array[counter_for_result_array] = char(temp);
          counter_for_result_array ++;
          
        }else if (temp_array[counter]=='A' || temp_array[counter] == 'C' ||(temp_array[counter]) == 'G' || (temp_array[counter]) == 'T'){
            result_array[counter_for_result_array] = temp_array[counter];
            counter_for_result_array ++;
        }
    }
    for (int count =0; count <counter_for_result_array; count++){
        cout<<result_array[count];
    }
    return 0;
}



int main(){
    char temp_array[1000];
    cin.get(temp_array , 1000);
    string_length(temp_array);
    return 0;
}