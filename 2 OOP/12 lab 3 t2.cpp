#include<iostream>
using namespace std;
// a)
class Circle{
    double radius;
    double originx;
    double originy;
    public:
    Circle(double radius1, double originx1, double originy1){
        radius = radius1;
        originx = originx1;
        originy = originy;
    }
    double setArea () {
     double area = 3.14 *radius*radius;
     return area;
    }
    double setCircumference () {
     double circumference = 2 * 3.14 * radius;
     return circumference;
    }
    double setDiameter () {
     double diameter = radius * 2;
     return diameter;
    }
};


int main () {
    double radius, originx,originy;
   cout<<"Enter Radius"<<endl;
   cin>>radius;
   cout<<"Enter OriginX"<<endl;
   cin>>originx;
   cout<<"Enter OriginY"<<endl;
   cin>>originy;
    Circle obj(radius,originx,originy);
    cout<<"Area is "<<obj.setArea()<<endl;
    cout<<"Circumference is "<<obj.setCircumference()<<endl;
    cout<<"Diameter is "<<obj.setDiameter()<<endl;

}