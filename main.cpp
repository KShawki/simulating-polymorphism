// Problem:     Simulating Polymorphism
// Submit:      https://cu.blackboard.com/ultra/courses/_35620_1
// Version:     v1.0

/*
 Team Members:
    [1] => Khalid Ibrahim Shawki        20206018        S3
    [2] => Abdelrahman Motaaz           20196032        S3
    [3] => Sohaila Gamal Ahmed          20196026        S1
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
#include <math.h>
using namespace std;

// struct containing the virtual function that will
// be changed based on the shape
struct ShapeVTable;

// that struct represent the parent -super- class
// which be inheritstruct Shape
struct Shape {
    //only has the virtual functions
    ShapeVTable* VTable;
};

struct ShapeVTable {
    //get the shape area
    double (*getArea)(Shape*);

    // get the shape data
    void (*PrintInfo)(Shape*);
    // free shape resources.
    void (*Destroy) (Shape*);
};

// to implement function getArea from the virtual table.
double getArea(Shape* shape) { shape->VTable->getArea(shape);}

// to implement function getInfo from the virtual table.
void PrintInfo(Shape* shape) { shape->VTable->PrintInfo(shape);}

// to implement function ShapeDestroy from the virtual table.
void Destroy(Shape* shape) { return shape->VTable->Destroy(shape); }

//Shape:Circle
struct Circle
{
     // aggregation with the -super class- shape
     // that representing the inheritance
    Shape parent;

    // radius of circle
    int radius;
};

//function that get the area of the circle
double CircleArea(Circle* circle)
{
    //area = 3.14*r^2
    return 3.14*circle->radius*circle->radius;
}

//function that get the info of the circle
void CircleInfo(Circle* circle)
{
    cout<<"Shape : Circle"<<endl;
    cout<<"Area : "<<CircleArea(circle)<<endl;
    cout<<"radius : "<<circle->radius<<endl;
}

// free shape resources.
void CircleDestroy(Circle* circle)
{
    delete circle;
}

//virtual table containing the overridden
//GetArea abstract function for the circle
ShapeVTable circleTable = {

    //casting circleArea function to
    //match getArea and getInfo abstract function
    (double(*)(Shape*)) CircleArea  ,
    (void(*)(Shape*)) CircleInfo ,
    (void (*) (Shape*)) CircleDestroy
};

//function that represent the constructor of the circle class
void CircleInitialize(Circle* circle, int radius)
{
    //initialize super class virtual
    //function to the overridden circleArea
    circle->parent.VTable =&circleTable;

    // initialize the circle radius
    circle->radius =radius;
}

// struct represent the inherited class rectangl
struct Rectangle
{
    // aggregation with the -super class- shape
    // that representing the inheritance
    Shape parent;

    // rectangle's height
    int height ;

    // rectangle's width
    int width;
};

//function that get the rectangle's area
double RectangleArea(Rectangle* rectangle)
{
    //area = height * width
    return rectangle->height * rectangle->width;
}

//function that get the info of the Rectangle
void RectangleInfo(Rectangle* rectangle)
{
    cout<<"Shape : Rectangle "<<endl;
    cout<<"Area : "<<RectangleArea(rectangle)<<endl;
    cout<<"height : "<<rectangle->height<<endl;
    cout<<"width : "<<rectangle->width<<endl;
}

// free shape resources.
void RectangleDestroy(Rectangle* rectangle) { delete rectangle;}

// virtual table containing
// the overridden GetArea abstract function for the rectangle
ShapeVTable rectangleTable = {
    // casting rectangleArea function to
    // match getArea and getInfo abstract function
    (double(*)(Shape*)) RectangleArea ,
    (void(*)(Shape*)) RectangleInfo ,
    (void(*)(Shape*)) RectangleDestroy
};

//representing the rectangle constructor
void RectangleInitialize(Rectangle* rectangle, int height, int width)
{
    //initialize super class virtual
    //function to the overridden rectangleArea
    rectangle->parent.VTable = &rectangleTable;

    // initialize height and width of the rectangle
    rectangle->height = height;
    rectangle->width = width;
}

// Struct represent the inherited class ellipse
struct Ellipse
{
    // aggregation with the -super class- shape
    // that representing the inheritance
    Shape parent;

    // ellipse's radius1
    int radius1;

    // ellipse's radius2
    int radius2;
};

// Function that get the ellipse's area
double EllipseArea(Ellipse* ellipse) { return 3.14 * ellipse->radius1 * ellipse->radius2; }

// Function that get the info of the Rectangle
void EllipseInfo(Ellipse* ellipse)
{
    cout<<"Shape : Ellipse"<<endl;
    cout<<"Area : "<<EllipseArea(ellipse)<<endl;
    cout<<"radius1 : "<<ellipse->radius1<<endl;
    cout<<"radius2 : "<<ellipse->radius2<<endl;
}

// Free shape resources.
void EllipseDestroy(Ellipse* ellipse) { delete ellipse;}

// virtual table containing the overridden
// GetArea abstract function for the ellipse
ShapeVTable ellipseTable = {

    // casting ellipseArea function to
    // match getArea abstract function
    (double(*)(Shape*)) EllipseArea ,
    (void(*)(Shape*)) EllipseInfo
};

// Function that represent the constructor of the ellipse class
void EllipseInitialize(Ellipse* ellipse, int radius1, int radius2)
{
    // initialize super class virtual function
    // to the overridden ellipseArea
    ellipse->parent.VTable =&ellipseTable;

    // initialize the ellipse radius1
    ellipse->radius1 = radius1;

    // initialize the ellipse radius2
    ellipse->radius2 = radius2;
}


int main(){

    Circle circle;
    // circle with radius 10
    CircleInitialize(&circle, 10);

    Rectangle rectangle;
    // rectangle with width 3 and height 5;
    RectangleInitialize(&rectangle, 3, 5);

    Ellipse ellipse;
    // ellipse with radius 10, 12
    EllipseInitialize(&ellipse, 10, 12);

    Shape* shapes[3];
    shapes[0]=(Shape*)&circle;
    shapes[1]=(Shape*)&rectangle;
    shapes[2]=(Shape*)&ellipse;

    double TotalArea = 0.0;

    for(int i = 0; i<3; i++)
    {
        double d = getArea(shapes[i]);
        TotalArea+=d;
        PrintInfo(shapes[i]);
    }


    cout<<"Total Area Of Shapes : "<<TotalArea<<endl;

    return 0; // Program Ended Successfully
}
