#include <iostream>

#include <fstream>

#include <vector>

using namespace std;


// bool array_finder(int array[], int value){
//     int i = 0;
//     bool a = false;
//     while (array[i] != '\0'){
//         if (array[i] == value){
//             a = true;
//             break;
//         }
//     }
//     return a;
// }


//
//int main(){
//    ifstream inFile;
// 
// inFile.open("Drivers.txt");
// string hello;
// int table[10] = {0,4,8,12,16,20,24,28,32,36};
// //inFile >> hello;
// string line;
// if (inFile.is_open()){
//     int counter = 0;
//     int a = 0;
//     while(getline(inFile,line)){
//         if (array_finder(table,counter)){
//         cout << a << " Truck Details: " << endl;
//         a += 1;
//         }
//         cout << line << endl;
//         counter += 1;
//         //break;
//     }    
//     inFile.close();
// }
// else{
//     cout << "File not opened" << endl;
//cout << inFile.rdbuf();
//return 0;



//int main(){
//    string line;
//    ifstream file;
//    int number;
//    vector<int> h;
//    file.open("Drivers.txt");
//    //int n;
//    for(int i=0;i<5;i++){
//        if (file >> line){
//            if (i > 0){
//            int n = stoi(line);
//                h.push_back(n);
//            }
//            else{
//                h.pushback(line);
//            }
//        }
//    }
//
//    for (int i=0; i < 4;i++ ){
//        cout << h[i] << endl;;
//    }
//    return 0;
//}