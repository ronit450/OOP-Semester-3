#include <iostream>
using namespace std;
class Payment{
  double amount_of_payment;
  public:
  Payment(){}
  Payment(double amount_of_payment):amount_of_payment(amount_of_payment){}
  void paymentDetails(){
      cout<<"Amount of cash payment: $"<<amount_of_payment<<endl;
  }
  double get_amount(){
      return amount_of_payment;
  }
};

class CashPayment: public Payment{
    public:
    CashPayment(double amount): Payment(amount){}
};
class CreditCardPayment:public Payment{
    string name_of_card;
    string expiration_date;
    string credit_card_no;
    public:
    CreditCardPayment(double amount, string name, string date, string credit_card_no):name_of_card(name), expiration_date(date), credit_card_no(credit_card_no), Payment(amount){}
    void paymentDetails(){
        cout<<"Amount of credit card payment: $"<<Payment::get_amount()<<endl;
        cout<<"Name on the credit card: "<<name_of_card<<endl;
        cout<<"Expiration date: "<<expiration_date<<endl;
        cout<<"Credit card number: "<<credit_card_no<<endl;
    }  
};

int main()
{
	CashPayment cp1(75.25);
	CashPayment cp2(36.95);
	CreditCardPayment ccp1(95.15, "Smith", "12/21/2009", "321654987");
	CreditCardPayment ccp2(45.75, "James", "10/30/2008", "963852741");

	cout << "Details of Cash #1..." << endl;
	cp1.paymentDetails();
	
	cout << "\nDetails of Cash #2..." << endl;
	cp2.paymentDetails();
	
	cout << "\nDetails of Credit Card #1..." << endl;
	ccp1.paymentDetails();
	
	cout << "\nDetails of Credit Card #2..." << endl;
	ccp2.paymentDetails();
		
	return 0;
}