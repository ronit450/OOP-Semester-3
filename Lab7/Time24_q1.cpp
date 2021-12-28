#include<iostream>

using namespace std;

class Time{
  int hours=0; int minutes=0; int seconds=0;
  public:
  Time adjust(Time result){
      while (result.hours >24 || result.minutes > 60 || result.seconds > 60){
        if (result.hours > 24){
            result.hours = result.hours - 24;
        }
        if (result.minutes > 60){
            result.hours += 1;
            result.minutes = result.minutes - 60;
        }
        if (result.seconds> 60){
            result.minutes += 1;
            result.seconds = result.seconds - 60;
        }
      }
        return result;
  }
  Time(int hour, int minute, int second): hours(hour), minutes(minute),seconds(second){
      Time result;
      result.hours = hour;
      result.minutes = minute;
      result.seconds = second;
      result = adjust(result);
      hours = result.hours;
      minutes = result.minutes;
      seconds = result.seconds;
  }
  Time(){
      
  }
  
  Time operator +(Time t2){
      Time result;
      result.hours = hours+t2.hours;
      result.minutes= minutes + t2.minutes;
      result.seconds = seconds + t2.seconds;
      result = adjust(result);
      return result;
  }
  void show(){
    if (hours<10 && minutes < 10 && seconds<10){
        cout<<"0"<<hours<<":0"<<minutes<<":0"<<seconds<<endl;
    }else if (hours < 10 && minutes >10){
        cout<<"0"<<hours<< ":"<<minutes<<":"<<seconds<<endl;
    }else if (hours <10 && minutes < 10){
        cout<<"0"<<hours<< ":0"<<minutes<<":"<<seconds<<endl;
    }else if (minutes < 10){
        cout<<hours<<":0"<<minutes<<":0"<<seconds<<endl;
    }else if (seconds < 10){
        cout<<hours<<":"<<minutes<<":0"<<seconds<<endl;
    }else{
        cout<<hours<<":"<<minutes<<":"<<seconds<<endl;
    }
        
    }   
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int hh, mm, ss;
    cin>>hh>>mm>>ss;
    Time t1(hh, mm, ss); //t1(hh, mm, ss)
    cin>>hh>>mm>>ss;
    Time t2(hh, mm, ss);
    Time t3;
    t3=t1+t2; //adding two times should produce a valid time, overflowed hours/minutes/seconds should be adjusted.
    // e.g. adding 18:10:20 with 10:20:30 results in 4:30:50
    
    t1.show();
    t2.show();
    t3.show();
    return 0;
}