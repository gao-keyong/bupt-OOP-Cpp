#include <iostream>
#include <cmath>

class Point
{
    friend class Circle;

public:
    // Constructor with default parameter values
    Point(double x = 0., double y = 0.) : x(x), y(y)
    {
        std::cout << "---Construct a Point object and set x = " << x << " and y = " << y << std::endl;
        system("pause");
    };
    ~Point()
    {
        std::cout << "---Destruct a Point object. " << std::endl;
        system("pause");
    }
    static double dist(const Point &p1, const Point &p2)
    {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        return sqrt(dx * dx + dy * dy);
    }

private:
    double x;
    double y;
};

class Circle
{
public:
    Circle(double r = 1.) : radius(r)
    {
        std::cout << "---Construct a Circle object and set (x, y) = (" << center.x << ", " << center.y << " and r = " << radius << std::endl;
        system("pause");
    };
    Circle(double x, double y, double r = 1.)
    {
        center.x = x;
        center.y = y;
        radius = r;
        std::cout << "---Construct a Circle object and set (x, y) = (" << center.x << ", " << center.y << ") and r = " << radius << std::endl;
        system("pause");
    }
    ~Circle()
    {
        std::cout << "---Destruct a Circle object. " << std::endl;
        system("pause");
    }
    static bool intersect(const Circle &o1, const Circle &o2)
    {
        double d = Point::dist(o1.center, o2.center);
        if (d < o1.radius + o2.radius && d > fabs(o1.radius - o2.radius))
        {
            return true;
        }
        return false;
    }

private:
    Point center;
    double radius;
};

int main(int argc, char const *argv[])
{
    double x1, y1, r1, x2, y2, r2;
    std::cout << "Input (x,y) and r of O1: " << std::endl;
    std::cin >> x1 >> y1 >> r1;
    std::cout << "Input (x,y) and r of O2: " << std::endl;
    std::cin >> x2 >> y2 >> r2;
    Circle O1(x1, y1, r1), O2(x2, y2, r2);
    if (Circle::intersect(O1, O2))
    {
        std::cout << "Intersect. " << std::endl;
    }
    else
    {
        std::cout << "Not intersect. " << std::endl;
    }
    return 0;
}
