#include "Shape.h"
#include <iostream>
#include <string>

std::string Shape::getType(int count)
{
    std::string shapeIs = " ";
        if (count > 6)
        {
            shapeIs = "Polygon";
            return shapeIs;
        }
        else if (count == 6)
        {
            shapeIs = "Triangel";
            return shapeIs;
        }
        else if (count == 4)
        {
            shapeIs = "Line";
            return shapeIs;
        }
        else if (count == 2)
        {
            shapeIs = "Point";
        }
        else
        {
            shapeIs = "Undefined";
            return shapeIs;
        }
    return shapeIs;
}

double Shape::area(double buffer, int count)
{
    double area = 0; 
    for(int i = 0; i < count; i++)
    area = 1/2(buffer[i](buffer[])
}