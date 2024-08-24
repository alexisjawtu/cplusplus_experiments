#include <math.h>

class Point3D
{
public:
    double x;
    double y;
    double z;

public:
    Point3D(/* args */);
    ~Point3D();

    Point3D(double x, double y, double z);
    Point3D(const Point3D& point);
    Point3D operator+(const Point3D& p) const;
    Point3D operator-(const Point3D& p) const;
    Point3D operator*(const double scale);
    Point3D operator/(const double scale);
    double operator*(const Point3D& p);  // inner product
    double norm();
};
