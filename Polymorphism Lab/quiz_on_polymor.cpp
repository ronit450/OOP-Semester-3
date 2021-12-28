#include<iostream>
using namespace std;

class Account{
  string title;
  int balance;
  public:
  Account(string title, int balance): title(title), balance(balance){
  }
  protected:
  int getBalance(){
      return balance;
  }
  public:
  virtual void showDetails(){
      if(balance >0){
        cout<<"Title: "<<title<<", Balance: "<<balance;
      }else{
          cout<<"Title: "<<title<<", Balance: "<<balance*-1;
      }
      
  }
  
    
};

class SavingAccount: public Account{
  int profit_ratio;
  public:
  SavingAccount(string title, int balance, int profit_ratio):Account(title, balance), profit_ratio(profit_ratio){}
  void showDetails(){
      Account::showDetails();
      cout<<", Profit: "<<((profit_ratio*0.01)*Account::getBalance())<<endl;
  }
    
};
class LoanAccount: public Account{
  int intrest_ratio;
  public:
  LoanAccount(string title, int balance, int intrest_ratio):Account(title, balance), intrest_ratio(intrest_ratio){}
    void showDetails(){
        Account::showDetails();
        cout<<", Interest: "<<(((intrest_ratio*0.01)* Account::getBalance())*-1)<<endl;
    }
};

int main(){
    int num_of_inp =0;
    Account *ptr;
    string title; int balance; int profit;
    cin>> num_of_inp;
    for(int count = 0; count<num_of_inp; count++){
        cin>> title; cin>> balance; cin>>profit;
        if(balance>0){
            ptr = new SavingAccount(title, balance, profit);
        }else{
            ptr = new LoanAccount(title, balance, profit);
        }
        ptr->showDetails();
        delete ptr;
    }
    
    return 0;
}