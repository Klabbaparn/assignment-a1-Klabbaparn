#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape
{
    public:
        std::string getType(int count);
        double area();
        /*double circumreference();
        double position();
        bool isConvex();*/
};

#endif // SHAPE_H