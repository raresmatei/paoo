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

        void printJob(){
            cout<<title<<"  "<<salary;
        }
};

class BaseEmployee{
    private:
        string type;
    public:
        string getType(){
            return type;
        }
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

class Employee: public BaseEmployee{
    private:
        string name;
        int age;
        Job job;
    public:
        Employee(string type, string nameVal, int ageVal, string titleVal, int salaryVal): BaseEmployee(type), job(titleVal, salaryVal){
            name = nameVal;
            age = ageVal;            
        }
        void swapFields(Employee& rhs){
            swap(job, rhs.job);
            age = rhs.age;
            name = rhs.name;
        }

        Employee& operator=(const Employee& rhs){
            cout<<"assignment operator"<<endl;
            BaseEmployee::operator=(rhs);
            Employee temp(rhs); 
            cout<<"temp name: "<<temp.getName()<<endl;
            swapFields(temp);
            return *this;
        }

        Employee(const Employee& rhs)
        : BaseEmployee(rhs),
         job(rhs.job)
        {          
            name = rhs.name;
            age = rhs.age;  
            cout<<"Employee copy constructor"<<endl;
        }

        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }

        Job getJob(){
            return job;
        }


};

int main(){
    Employee e1("part-time", "ana", 25, "eng", 2000);
    Employee e2("full-time","rares", 21, "it", 3000);

    e1 = e2;

    cout<<"e1: "<<e1.getType()<<" "<<e1.getName()<<" "<<e1.getAge()<<" ";
    e1.getJob().printJob();

}