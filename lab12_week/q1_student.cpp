#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Student{
    int student_id; 
    string last_name;
    double GPA;
    public:
    Student(): student_id(0), last_name("None"){}
    Student(int student_id, string last_name, double GPA): student_id(student_id), last_name(last_name), GPA(GPA){} 
    
    void display(){
        cout<<student_id<<" "<<last_name<<" "<<GPA<<endl;
    }
    int get_id(){
        return student_id;
    }
    friend bool operator<(const Student& s1, const Student& s2);
    friend bool operator==(const Student& s1, const Student& s2);
    
};
bool operator<(const Student& s1, const Student& s2){
    if(s1.student_id < s2.student_id){
        return true;
    }
    
    else{
        return false;
    }
}

bool operator==(const Student& s1, const Student& s2){
    if(s1.student_id == s2.student_id){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int id;
    string name;
    double GPA;
    set <Student> set_student;
    cout<<"Number of entries = 5"<<endl;
    for(int i = 0; i<5;i++){
        cin>>id>>name>>GPA;
        Student S1(id,name,GPA);
        set_student.insert(S1);
    }
    int search_id = 0;
    cin>>search_id;
    Student result;
    bool isFound = false;
    for (auto count: set_student){
        if (count.get_id() == search_id){
            result = count;
            isFound = true;
        }
        count.display();
    }
    if (isFound == true){
        cout<<"Searched student is:"<<endl;
        result.display();
    }else{
        cout<<"No such ID exists!"<<endl;
    }
    return 0;
}