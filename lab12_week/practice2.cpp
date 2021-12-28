#include <iostream>
using namespace std;
#include <list>
#include <algorithm>
int main(){
    list <int> samople_list = {1,5,3,6,9,8,5,11};
    samople_list.push_front(5);
    samople_list.remove(5);
    // for (auto count: samople_list){
    //     cout<<count<<" ";
    // }

    // If we have a list of type pointer as lets say
    // list <Distance*> l1;
    //so to iterate over it we use iterator to iterate over the list.
    // for(list<int>::iterator it = samople_list.begin(); it!= samople_list.end(); it++){
    //     cout<<*it<<" ";
    //     // To Derefrence we are using * before it to print the value
    // }

    //Below loop is the same as the above just using auto to make our life simple
    for(auto it = samople_list.begin(); it!= samople_list.end(); it++){
        cout<<*it<<" "<<endl;
        // To Derefrence we are using * before it to print the value
    }

    // There is a find function in c++ which helps us to find that 
    // Whether particular element is there is the list ot not
    // it taks three arguments, begin intertor, end iterator, and the value

    auto it = find(samople_list.begin(), samople_list.end(), 9);
    if (it != samople_list.end()){
        cout<<"element found"<<endl;
    }else {
        cout<<"element not found"<<endl;
    }

    // to check whether element has been found or not. check if it = the last value. if it is equal then found if not then not found
    return 0;
}
