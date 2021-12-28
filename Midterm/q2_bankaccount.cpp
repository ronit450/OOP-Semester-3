#include <iostream>
using namespace std;

class BankAccount{
  string account_title;
  int balance = 0; int limit = 0;
  public:
  BankAccount(){     
  }  
  BankAccount(string title, int bal): account_title(title), balance(bal){
  }
  BankAccount(string title, int bal, int lim): account_title(title), balance(bal), limit(lim){    
  }
  
  void deposit(int amount){
    balance = balance + amount;
  }
  void withdraw(int amount){
      bool request;
      if (amount > limit){
          cout<<"Withdraw Failed: daily limit is: "<<limit<<endl;
      }else{
          if (amount < balance){
            balance = balance - amount;
            cout<<"Withdraw Success"<<endl;
          }else{
              cout<<"Withdraw Failed: balance is insufficient."<<endl;
          }
      }
  }
  void closing_balance(){
      cout<<"Closing Status: "<<endl<< "Title: "<<account_title<<", Current Balance: "<<balance<<", Daily limit: "<<limit;
  }

  
};

int main(){
    string account_title;
    int balance = 0; int limit = 0;
    char operation = 'a';
    int amount;
    cin >> account_title;
    cin >> balance; 
    cin >> limit;
    BankAccount b1 = {account_title, balance, limit};
    
    while (operation != 'q'){
        cin>> operation;
        cin>> amount;
        if (operation == 'w'){
            b1.withdraw(amount);
        }else if (operation == 'd'){
            b1.deposit(amount);
        }else if (operation == 'q'){
            b1.closing_balance();
        }
    }
    
    
  
    
}