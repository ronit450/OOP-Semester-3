#include <iostream>
using namespace std;

template <class T, class U>
T abs (T x ) {
    T result;
    if (x <0){
        result = -x;
    }else {
        result = x;
    }
    return result;
}
// Template class is used when we dont know what will be sent to the function
// so here T will be determined by the value we pass through. 
int main(){
    cout<<abs(-50)<<endl;;
    return 0;
}