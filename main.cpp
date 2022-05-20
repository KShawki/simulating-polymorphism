// Problem:     Simulating Polymorphism
// Submit:      https://cu.blackboard.com/ultra/courses/_35620_1
// Version:     v1.0

/*
 Team Members:
    [1] => Khalid Ibrahim Shawki        20206018        S3
    [2] => Abdelrahman Motaaz           20196032        S3
    [3] => Sohaila Gamal Ahmed          20196026        S3
    [4] => Ahmed Mohammed Idrees        20176003        S3
    [5] => Noran Mohammed               20176041        S3
*/

/*
Problem Statement:
    Implement base struct Shape and derived struct Circle, Rectangle and Ellipse simulating polymorphism
    without using the virtual keyword. Do not use the C++ inheritance or polymorphism mechanisms but simulate
    them as described in our lecture "Lecture05_GenericProgram".
    You are allowed to use some lecture code. Your code must be general.
*/

#include <iostream>
using namespace std;

// Declare the Base Structure
struct Shape {
    double area;
    //function to return area of shape
    double getArea() { return area; }
    double ShapeInfo;
    double ShapeInfo2;
    //function to return info of shape
    double printInfo() { return ShapeInfo ; }
    double printInfo2() { return ShapeInfo2 ; }
};

// compute the area for that paricular shape to get area of circle
struct Circle:Shape {
    double radius;
    void info() {
        ShapeInfo = radius;
        }
    void calcArea() {
        area = 3.14 * radius * radius;
        }
};

// to get area of rectangle
struct Rectangle:Shape{
    double width,height;
    void info()
    {
        ShapeInfo = width ;
    }
    void info2()
    {
        ShapeInfo2 = height;

    }
    void calcArea() {
        area = width * height;
        }
};

// to get area of ellipse
struct Ellipse:Shape{
    double radius1;
    double radius2;

    void info()
    {
        ShapeInfo = radius1;

    }
    void info2()
    {
        ShapeInfo2 = radius2;
    }
    void calcArea() {
        area = 3.14 * radius1 * radius2;
         }
};

// Inilize the Circle and compute the area
void CircleInitialize (Circle* circle, double radius)
{
    circle -> radius = radius;
    circle -> calcArea();
    circle -> info();
}

// Initlize the rectangle and compute the area
void RectangleInitialize (Rectangle* rectangle,double width,double height)
{
    rectangle -> width = width;
    rectangle -> height = height;
    rectangle -> calcArea();
    rectangle -> info();
    rectangle -> info2();

}

//Initlize the ellipse and compute the area
void EllipseInitialize (Ellipse* ellipse, double radius1, double radius2){

    ellipse -> radius1 = radius1;
    ellipse -> radius2 = radius2;
    ellipse -> calcArea();
    ellipse -> info();
    ellipse -> info2();
}

// Return the area of each shape
double GetArea (Shape *shape) {
    return shape -> getArea();
    }

// Return the info of each shape
double PrintInfo(Shape *shape) {
    return shape -> printInfo();
    }

// Return the info of each shape
double PrintInfo2(Shape *shape) {
    return shape -> printInfo2();
    }


int main(){

    // circle with radius 10
    Circle circle;
    CircleInitialize(&circle, 10);

    // rectangle with width 3 and height 5;
    Rectangle rectangle;
    RectangleInitialize(&rectangle, 3, 5);

    // ellipse with radius 10, 12
    Ellipse ellipse;
    EllipseInitialize(&ellipse, 10, 12);

    Shape* shapes[3];
    shapes[0]=(Shape*)&circle;
    shapes[1]=(Shape*)&rectangle;
    shapes[2]=(Shape*)&ellipse;

    double total_area = 0.0;

    for(short i = 0; i<3; i++)
    {
        double d = GetArea(shapes[i]);
        total_area = total_area + d;
        PrintInfo(shapes[i]);


    }
        cout<<"Total Area Of Shapes = "<<total_area<<endl;
        cout<<"shape0: redius="<<" "<<PrintInfo(shapes[0])<<endl<<"shape1: width = "<<" "<<PrintInfo(shapes[1])<<" , "
        <<"height = "<<PrintInfo2(shapes[1])<<endl<<"shape2: radius1 ="<<" "<<PrintInfo(shapes[2])<<" , "
        <<"radius2 = "<<PrintInfo2(shapes[2]);



    return 0; // Program Ended Successfully
}
