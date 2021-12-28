#include <iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <map>

// map in c++ is like the dictionary in python. we get two values, one is key and other is value
int main(){
    map<int, string> sample_map;
    sample_map[1]= "hello";
    sample_map[30]= "Ronit";
    sample_map.insert({2, "Faraz"});
    cout<<sample_map[2]<<endl;

    for (auto count: sample_map){
        cout<<count.second<<" ";
    }
    cout<<endl;
    // So map always stores the sorted data on the basis of keys. 
    // like here it will display hello first and then faraz first because the key 
    // of faraz is less than the key of Ronit.


    if(sample_map[10] == "Murtaza"){
        cout<<"I am Murtaza"<<endl;
    }
    // So Here we can see that sample_map[10] does not exsist so it will not check this condition 
    //rather will insert the null value with key 10.

    cout<<"The key is "<<sample_map[10]<<"and the value it has"<<endl;

    if (sample_map.find(6) != sample_map.end()){
        cout<<"element is found with value 2"<<endl;
    }else{
        cout<<"element is not found with value 2"<<endl;
    }

    // to knoe the value at any key
    cout<<sample_map.at(2)<<endl;
    
    return 0;
}