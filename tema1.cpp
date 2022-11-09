#include<iostream>
using namespace std;
#include<math.h>

const string RECTANGLE = "rectangle";
const string TRIANGLE = "triangle";

class Uncopyable {
    protected:                                // allow construction and destruction of derived objects.
        Uncopyable(){
            cout<<"uncopiable ctor"<<endl;
        };
        ~Uncopyable(){};
    private:
        Uncopyable(const Uncopyable&);        // ...but prevent copying
        Uncopyable& operator=(const Uncopyable&);
};

class A:Uncopyable{
};

class Shape: Uncopyable{
    private:
        string type;
    public:
        Shape(string typeVal): Uncopyable(){
            type = typeVal;
            cout<<"shape constructor: "<<typeVal<<endl;
        }
        Shape(Shape const&){
            cout<<"copy shape ctor"<<endl;
        }
        virtual ~Shape(){
            cout<<"delete shape"<<endl;
        }
        virtual double getArea() = 0;
};

class Rectangle: Shape{
    private:
        double length;
        double width;

        // Rectangle(const Rectangle&);        // ...but prevent copying
        // Rectangle& operator=(const Rectangle&);
    
    public:
        Rectangle(double lengthVal, double widthVal): Shape(RECTANGLE)
        {
            length = lengthVal;
            width = widthVal;
            cout<<": "<<length<<" "<<width<<endl;
        }
        ~Rectangle(){
            cout<<"delete rectangle"<<endl;
        }
        // Rectangle(const Rectangle&): Shape(RECTANGLE){
        //     cout<<"copy ctor rec"<<endl;
        // }
        double getLength(){
            return length;
        }
        double getWidth(){
            return width;
        }
        void setLength(double lengthVal){
            this->length = lengthVal;
        }
        void setWidth(double widthVal){
            width = widthVal;
        }
        double getArea(){
            return length * width;
        }

};

class Triangle: Shape{
    private:
        double l1;
        double l2;
        double l3;
    
    public:
        Triangle(double l1Val, double l2Val, double l3Val): Shape(TRIANGLE)
        {
            l1 = l1Val;
            l2 = l2Val;
            l3 = l3Val;

            if (l1 < 0 || l2 < 0 || l3 < 0 || (l1 + l2 <= l3) || l1 + l3 <= l2 || l2 + l3 <= l1)
            {
                cout << "Not a valid triangle"<<endl;
                exit(0);
            }

            cout<<": "<<l1<<" "<<l2<<" "<<l3<<endl;
        }
        ~Triangle(){
            cout<<"delete triangle"<<endl;
        }
        double getL1(){
            return l1;
        }

        void setL1(double l1Val){
            l1 = l1Val;
        }

        double getL2(){
            return l2;
        }

        void setL2(double l2Val){
            l2 = l2Val;
        }

        double getl3(){
            return l3;
        }

        void setL3(double l3Val){
            l3 = l3Val;
        }

        double getArea(){
            float s = (l1 + l2 + l3) / 2;
            return sqrt(s * (s - l1) *
                    (s - l2) * (s - l3));
        }

};

int main(){
    Rectangle rectangle1(2,5);
    Rectangle rectangle3(rectangle1);

    Triangle triangle1(12, 9, 5);
}