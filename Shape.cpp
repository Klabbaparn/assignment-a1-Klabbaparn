#include "Shape.h"
#include <iostream>
#include <string>

std::string Shape::getType(double buffer, int count)
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

double Shape::getArea(double *buffer)
{
    double area = 0;
    area = abs((buffer[0] * (buffer[3] - buffer[5]) + buffer[2] * (buffer[5] - buffer[1]) + buffer[4] * (buffer[1] - buffer[3])) / 2);
    if (area == 0)
    {
        area = -1;
        return area;
    }
    else
        return area;
}