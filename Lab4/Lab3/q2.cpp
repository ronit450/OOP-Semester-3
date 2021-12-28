#include <iostream>
using namespace std;
int print_matrix(int dimensions, int result_array[]){
    int temp= 0;
    temp = dimensions/2;
    for(int counter = 0; counter<dimensions;counter++){
        if (counter == temp){
            cout<<endl;
        } 
        cout<<result_array[counter]<<" ";
    }
    return 0;
}
int add_matrixs(int dimensions, int array1[], int array2[] ){
    int result_array [dimensions];
    int temp;
    for(int counter = 0; counter<dimensions;counter++){
      temp = array1[counter] + array2[counter];
      result_array[counter] = temp;
    }
    print_matrix(dimensions, result_array);
    return 0;
}
int subtract_matrix(int dimensions, int array1 [], int array2 []){
    int result_array [dimensions];
    int temp;
    for(int counter = 0; counter<dimensions;counter++){
      temp = array1[counter] - array2[counter];
      result_array[counter] = temp;
   }
   print_matrix(dimensions, result_array);
   return 0;
}
int input_matrix(int dimensions){
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
        add_matrixs(dimensions, array1, array2);
    }else if (operator_for_vector == '-'){
        subtract_matrix(dimensions, array1, array2);

    }
    return 0;
}

int main(){
  int dimensions;
  int row;
  int column;
  cin>> row;
  cin>> column;
  dimensions = row*column;
  input_matrix(dimensions);
  return 0;
  }
  