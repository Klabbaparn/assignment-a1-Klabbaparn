#ifndef POINT_H
#define POINT_H
#include <string>

class Point: public Shape{
  public:
    double Point(double x, double y) : m_x(x), m_y(y) {}
    double getX() const { return m_x; }
    double getY() const { return m_y; }

  private:
    double m_x;
    double m_y;
};

#endif // POINT_H