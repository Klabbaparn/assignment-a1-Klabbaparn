#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape
{
    public:
        std::string getType(double buffer, int);
        double getArea(double *buffer);
        /*double circumreference();
        double position();
        bool isConvex();*/
};

#endif // SHAPE_H