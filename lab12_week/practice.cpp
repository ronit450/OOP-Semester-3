#include <iostream>
#include <vector>
using namespace std;

int main(){
    auto A = {"Ronit", "Faraz", "Murtaza"};
    for (auto count: A){
        cout<<count<<endl;
    }
    vector<int> B = {1,2,3,4,5,6,7};
    B.push_back(4);
    for (int value: B){
        cout<<value<<endl;
    }
    for (int i = 0; i < 50; i++){
        cout<<B.at(i)<<endl;
    }
    return 0;
}