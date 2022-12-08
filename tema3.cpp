#define _HAS_AUTO_PTR_ETC 1
#include <iostream>
#include <vector>
#include<memory>

using namespace std;

class Employee{
    private:
        string name;
        bool isLocked = false;
    
    public:
        Employee(){
            cout<<"Ctor employee 1"<<endl;
        }
        Employee(string nameVal){
            cout<<"Ctor employee 2"<<endl;
            name = nameVal;
        }
        string getName(){
            return name;
        }
        void setName(string nameVal){
            name = nameVal;
        }
        bool getIsLocked() {
            return isLocked;
        }

        void setIsLocked(bool isLockedVal) {
            isLocked = isLockedVal;
        }
};

Employee* createEmployeeInstance(string name) {
    return (new Employee(name));
};

void lock(Employee& employee) {
    std::cout<<"employee blocked"<<endl;
    employee.setIsLocked(true);
};

void unlock(Employee& employee) {
    std::cout<<"employee unblocked"<<endl;
    employee.setIsLocked(false);
};

class Lock {
    private:
        Employee& lockPtrEmployee;
    public:
        Lock(Employee& ptr): lockPtrEmployee(ptr) {
            lock(lockPtrEmployee);
        }
        ~Lock() {
            unlock(lockPtrEmployee);
        }
};

int main(){
    cout<<"sadf"<<endl;
    auto_ptr<Employee> empl1(createEmployeeInstance("ana"));
    cout<<empl1->getName()<<endl;

    auto_ptr<Employee> empl2(empl1); 
    cout<<empl2->getName()<<endl;
    //cout<<empl1->getId()<<endl;

    shared_ptr<Employee> empl1Shared(createEmployeeInstance("rares"));
    cout<<empl1Shared.use_count()<<endl;

    shared_ptr<Employee> empl2Shared(empl1Shared);

    cout<<empl1Shared.use_count()<<endl;

    empl2Shared->setName("george");
    cout<<empl1Shared->getName()<<endl; 

    shared_ptr<Employee> empl3Shared(empl1Shared);
    cout<<empl1Shared.use_count()<<endl;
    cout<<empl2Shared.use_count()<<endl;
    cout<<empl3Shared.use_count()<<endl;

    //-----------------------------------------------

    Employee employee("rares");
    Lock* emplLocked = new Lock(employee);
    cout<<employee.getIsLocked()<<endl;
    delete emplLocked;
    cout<<employee.getIsLocked()<<endl;
}