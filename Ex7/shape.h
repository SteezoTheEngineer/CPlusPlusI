#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
//Base class
class Shape
{
protected:
std::string m_type = "shape";

public:
    Shape(std::string type);
    virtual ~Shape(){std::cout<<"Shape destructor called"<<std::endl;};
    virtual double getArea() = 0;
    virtual double getCircumference() = 0;
    virtual void report();


};

class Triangle final: public Shape 
{

public:
    Triangle(double length, double height);
    virtual ~Triangle(){std::cout<<"Triangle destructor called"<<std::endl;};
    double getArea() override;
    double getCircumference() override;
    double m_length;
    double m_height;
};

class Square: public Shape 
{

public:
    Square(double length);
    virtual ~Square(){std::cout<<"Square destructor called"<<std::endl;};
    double getArea() override;
    double getCircumference() override;
    double m_length;
};

class Circle: public Shape 
{

public:
    Circle(double radius);
    virtual ~Circle(){std::cout<<"Circle destructor called"<<std::endl;};
    double getArea() override;
    double getCircumference() override;
    double m_radius;
};

#endif // SHAPE_H