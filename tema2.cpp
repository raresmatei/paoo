#include<iostream>

using namespace std;

class Job{
    private:
        string title;
        int salary;
    public:
        Job(string titleVal, int salaryVal){
            title = titleVal;
            salary = salaryVal;
        }
};

class BaseEmployee{
    private:
        string type;
    public:
    BaseEmployee(string typeVal){
        type = typeVal;
    }
    BaseEmployee(const BaseEmployee& rhs)
    : type(rhs.type)
    {
        cout<<"base copy constructor"<<endl;
    }
    BaseEmployee& operator=(const BaseEmployee& rhs)
    {
        cout<<"base copy assignment operator"<<endl;
        type = rhs.type; 
        return *this; 
    }
};

class Employee: BaseEmployee{
    private:
        string name;
        int age;
        Job job;
    public:
        Employee(string nameVal, int ageVal, string titleVal, int salaryVal): job(titleVal, salaryVal), BaseEmployee("full-time"){
            name = nameVal;
            age = ageVal;            
        }
        void swapFields(Employee& rhs){
            swap(job, rhs.job);
        }

        Employee& operator=(const Employee& rhs){
            cout<<"assignment operator"<<endl;
            BaseEmployee::operator=(rhs);
            Employee temp(rhs); 
            swapFields(temp);
            return *this;
        }

        Employee(const Employee& rhs)
        : BaseEmployee(rhs),
         job(rhs.job)
        {
            cout<<"Employee copy constructor"<<endl;
        }
        };

int main(){
    Employee e1("ana", 25, "eng", 2000);
    Employee e2("rares", 21, "it", 3000);

    e1 = e2;
    cout<<"--------------------"<<endl;
    Employee e3(e2);
}