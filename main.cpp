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

#include<iostream>
#include <cmath>
using namespace std;

// Declare the Base Structure
struct Shape {
    double area;
    double getArea() { return area; }
    double infoOfShape;
    double printInfo() { return infoOfShape; }
};

// compute the area for that paricular shape to get area of circle
struct Circle:Shape {
    double radius;
    void info() { infoOfShape = radius; }
    void calcArea() { area = 3.14 * radius * radius; }
};

// to get area of rectangle
struct Rectangle:Shape{
    double width,height;
    void info()
    {
        infoOfShape = width;
        // infoOfShape = height ;
    }
    void calcArea() { area = width * height; }
};

// to get area if ellipse
struct Ellipse:Shape{
    double rad1;
    double rad2;

    void info()
    {
        infoOfShape= rad1;
        //infoOfShape= rad2;
    }
    void calcArea() { area = 3.14 *rad1 *rad2; }
};

// Inilize the Circle and compute the area
void CircleInitialize(Circle* circle, double radius)
{
    circle -> radius = radius;
    circle -> calcArea();
    circle -> info();
}


// Initlize the rectangle and compute the area
void RectangleInitialize(Rectangle* rectangle,double width,double height)
{
    rectangle -> width = width;
    rectangle -> height = height;
    rectangle -> calcArea();
    rectangle -> info();
}


//Initlize the ellipse and compute the area
void EllipseInitialize(Ellipse* ellipse,double radius_1, double radius_2){
    ellipse -> rad1 = radius_1;
    ellipse -> rad2 = radius_2;
    ellipse -> calcArea();
    ellipse -> info();
}

// Return the area of thea shape
double GetArea(Shape *s)
{

    return s -> getArea();

}

// Return the info of each shape
double PrintInfo(Shape *s)
{
    return s -> printInfo();
}


int main(){

    Circle circle;
    // circle with radius 10
    CircleInitialize(&circle, 10);

    // rectangle with width 3 and height 5 Square square;
    Rectangle rectangle;
    RectangleInitialize(&rectangle, 3, 5);

    // ellipse with radius 10, 12
    Ellipse ellipse;
    EllipseInitialize(&ellipse, 10, 12);

    Shape* shapes[3];
    shapes[0]=(Shape*)&circle;
    shapes[1]=(Shape*)&rectangle;
    shapes[2]=(Shape*)&ellipse;

    double total_area=0;
    double info0=0;
    double info1=0;
    double info2=0;

    int i;

    for(i=0;i<3;i++) {
        double d=GetArea(shapes[i]);
        // prints (cout) the radius if circle,
        // width and height if rectangle, ... etc

        total_area+=d;
        // print info of each shape
        PrintInfo(shapes[i]);
        info0=PrintInfo(shapes[i]);
        i++;
        info1=PrintInfo(shapes[i]);
        i++;
        info2=PrintInfo(shapes[i]);
    }

    cout<<"The Total Area: "<< total_area <<endl;
    cout<<"The Info Of Shape0 : "<<info0<<endl<<"The Info Of Shape1 : "
        <<info1<<endl<<"The Info Of Shape2 : "
        <<info2<<endl;
    return 0;
}
