#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int clockin(){
    time_t num = time(0);
    return num;
}

class Date{
    private:
        int day;
        int month;
        int year;
    
    public:
        Date(){
            year = 1900;
            day = 1;
            month = 1;
        }
        
        bool initialize(int, int, int);
        string get_formatted_date();
};

bool Date::initialize(int day, int mon, int year){
    if(day>0 && day<32 && mon>0 && mon<13 && year > 1900){
        day = day;
        month = mon;
        year = year;
        return true;
    }
    else {
        return false;
    }
}

string Date::get_formatted_date(){
    if(initialize(day, month, year)){
        string result = to_string(year) + ", " + to_string(month) + " - " + to_string(day);
        return result;
    }
    else{
    cout<<"The requirements are not satisfied";
    return 0;
    }
}

class Student{
    public:
        string first_name;
        string last_name;
        Date birth_date;
        string faculty;
        string id;
        
        Student(string name, string surn, string fac){
            first_name = name;
            last_name = surn;
            faculty = fac;
            id = "AUA_"+faculty+"_"+to_string(clockin());
        }
        
        Student(const Student& a){
            faculty = a.faculty;
            id = "AUA_"+faculty+"_"+to_string(clockin());
        }
        
        void set_birth_date(int day, int mon, int year){
            Date birth_date;
            if(!birth_date.initialize(day, mon, year)){
                cout<<"problem"<<endl;
            }
        }
        
        void set_name(string name, string sur){
            first_name = name;
            last_name = sur;
        }
        
        string get_birth_date(){
            string date = birth_date.get_formatted_date();
            return date;
        }
        
        string get_first_name(){
            return first_name;
        }
        
        string get_last_name(){
            return last_name;
        }
        
        string get_id(){
            return id;
        }
};

int main()
{
Student s("Aram", "Grigoryan", "CS"); //constructor
s.set_birth_date(12, 7, 1995);

Student d(s); //copy constructor
d.set_name("Anna", "Sargsyan");
d.set_birth_date(1, 5, 1995);

std::cout << "Below is the information about the registered students"
<< std::endl;
std::cout << s.get_first_name() << " " << s.get_id()<< std::endl;
std::cout << s.get_birth_date() << std::endl;

std::cout << d.get_first_name() << " " << d.get_id()<< std::endl;
std::cout << d.get_birth_date() << std::endl;

}
