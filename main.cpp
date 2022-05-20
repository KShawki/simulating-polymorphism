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
    double getArea() { return area; }
    double ShapeInfo;
    double printInfo() { return ShapeInfo; }
};

// compute the area for that paricular shape to get area of circle
struct Circle:Shape {
    double radius;
    void info() { ShapeInfo = radius; }
    void calcArea() { area = 3.14 * radius * radius; }
};

// to get area of rectangle
struct Rectangle:Shape{
    double width,height;
    void info()
    {
        ShapeInfo = width;
        // infoOfShape = height ;
    }
    void calcArea() { area = width * height; }
};

// to get area if ellipse
struct Ellipse:Shape{
    double radius_1;
    double radius_2;

    void info()
    {
        ShapeInfo = radius_1;
        //infoOfShape= radius_2;
    }
    void calcArea() { area = 3.14 * radius_1 * radius_2; }
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
}

//Initlize the ellipse and compute the area
void EllipseInitialize (Ellipse* ellipse, double radius_1, double radius_2)
{
    ellipse-> radius_1 = radius_1;
    ellipse -> radius_2 = radius_2;
    ellipse -> calcArea();
    ellipse -> info();
}

// Return the area of thea shape
double GetArea (Shape *shape) { return shape -> getArea(); }

// Return the info of each shape
double PrintInfo(Shape *shape) {  return shape -> printInfo(); }

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

    for (short i = 0; i<3; i++)
    {
        double d = GetArea(shapes[i]);
        total_area = total_area + d;
        PrintInfo(shapes[i]);
    }

    cout << total_area << endl;

    return 0; // Program Ended Successfully
}