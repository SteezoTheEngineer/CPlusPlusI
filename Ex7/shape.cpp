#include "shape.h"
#include <iostream>
#include <cmath>

Shape::Shape(std::string type):m_type(type)
{

}

double Shape::getArea(){
return 0;
}

double Shape::getCircumference(){
return 0;
}

void Shape::report(){
std::cout<< m_type <<" has area :"<< getArea() <<" and circumference : "<< getCircumference()<<std::endl;
}


Triangle::Triangle(double length, double height) :Shape("Triangle"), m_length(length), m_height(height) // Calls base class constructor
{

}

double Triangle::getArea()
{
return m_length*m_height*0.5;
}

double Triangle::getCircumference()
{
return 2*sqrt(pow(0.5*m_length, 2)+pow(m_height, 2)) + m_length;
}




Square::Square(double length) :Shape("Square"), m_length(length) 
{

}

double Square::getArea()
{
return pow(m_length, 2);
}

double Square::getCircumference()
{
return 4*m_length;
}




Circle::Circle(double radius) :Shape("Circle"), m_radius(radius) 
{

}

double Circle::getArea()
{
return  3.14159265358979323846*pow(m_radius,2);
}

double Circle::getCircumference()
{
return 2*m_radius*3.14159265358979323846;
}

