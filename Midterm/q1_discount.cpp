#include <iostream>
using namespace std;
int crazySale(int nItems){
    int discount = 0;
    int temp = 0;
    if (nItems == 0){
        discount = 0;
    }else if (nItems == 1){
        discount = 10;
    }else if (nItems <5){
        temp = nItems - 1;
        temp = temp*2;
        discount = 10 + temp;
    }else if (nItems == 5){
        discount = 20;
    }else if (nItems > 5){
        temp = nItems-5;
        temp = temp * 5;
        discount = 20 + temp;
    }
    if (discount > 70){
        discount = 70;
    }
    return discount;
}
int main() {
    int nItems;
    cin>>nItems;
    cout<<crazySale(nItems);
    return 0;
}