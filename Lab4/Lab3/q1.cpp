#include <iostream>
using namespace std;
int print_vector(int dimensions, int result_array[]){
    for(int counter = 0; counter<dimensions;counter++){
        cout<<result_array[counter]<<" ";
    }
    return 0;
}
int add_vectors(int dimensions, int array1[], int array2[] ){
    int result_array [dimensions];
    int temp;
    for(int counter = 0; counter<dimensions;counter++){
      temp = array1[counter] + array2[counter];
      result_array[counter] = temp;
    }
    print_vector(dimensions, result_array);
    return 0;
}
int subtract_vector(int dimensions, int array1 [], int array2 []){
    int result_array [dimensions];
    int temp;
    for(int counter = 0; counter<dimensions;counter++){
      temp = array1[counter] - array2[counter];
      result_array[counter] = temp;
   }
   print_vector(dimensions, result_array);
   return 0;
}
int compare_vectors(int dimensions, int array1 [], int array2 []){
    int temp = 0 ;
    for(int counter = 0; counter<dimensions;counter++){
        if (array1[counter] == array2[counter]){
            temp++;
            
        }else {
            cout<<"UNEQUAL";
            return 0;
        }
    }if (temp == dimensions){
        cout<<"EQUAL";
    }
    return 0;
}
int input_vector(int dimensions){
    int array1 [dimensions];
    int array2 [dimensions];
    int temp;
    for(int counter = 0; counter<dimensions;counter++){
      cin>> array1[counter];
    }
    for(int counter = 0; counter<dimensions;counter++){
      cin>> array2[counter];
    }
    char operator_for_vector;
    cin>> operator_for_vector;
    if (operator_for_vector == '+'){
        add_vectors(dimensions, array1, array2);
    }else if (operator_for_vector == '-'){
        subtract_vector(dimensions, array1, array2);
    }else {
        compare_vectors(dimensions, array1, array2);
    }
    return 0;
}

int main(){
  int dimensions;
  cin>> dimensions;
  input_vector(dimensions);
  return 0;
  }
  