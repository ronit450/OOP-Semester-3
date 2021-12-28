#include <iostream>
using namespace std;
class publication{
  string title;
  float price;
  public:
  publication(): title(""), price(0){}
  void getdata(){
      getline(cin, title);
      cin>> price;
  }
  void putdata(){
      cout<<"Publication title: "<< title<<endl;
      cout<<"Publication price: "<<price<<endl;
  }
  
  
};
class book : public publication{
  int page_count;  
  public:
  book() :  page_count(0){}
  void getdata(){
      publication::getdata();
      cin>> page_count;
  }
  void putdata(){
      publication::putdata();
      cout<<"Book page count: "<<page_count<<endl;
  }
 
  
};
class tape : public publication{
    float playing_time;
    public:
    tape(): playing_time(0){}
    void getdata(){
        publication::getdata();
        cin>> playing_time;
    }
    void putdata(){
      publication::putdata();
      cout<<"Tape's playing time: "<<playing_time<<endl;
  }
};
int main()
{
    book b;
    tape t;
    b.getdata();
    cin.ignore();
    t.getdata();
    b.putdata();
    t.putdata();
}