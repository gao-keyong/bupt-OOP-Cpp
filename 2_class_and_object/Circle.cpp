#include <iostream>
#include <cmath>

class Point
{
    friend class Circle;

public:
    Point() : x(0.), y(0.)
    {
        std::cout << "---Construct a Point object and set x = " << x << " and y = " << y << std::endl;
        system("pause");
    };
    Point(double x, double y) : x(x), y(y)
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
    Circle() : radius(1.)
    {
        std::cout << "---Construct a Circle object and set (x, y) = (" << center.x << ", " << center.y << " and r = " << radius << std::endl;
        system("pause");
    };
    Circle(double r) : radius(r)
    {
        std::cout << "---Construct a Circle object and set (x, y) = (" << center.x << ", " << center.y << " and r = " << radius << std::endl;
        system("pause");
    };
    Circle(double x, double y)
    {
        center.x = x;
        center.y = y;
        radius = 1.;
        std::cout << "---Construct a Circle object and set (x, y) = (" << center.x << ", " << center.y << " and r = " << radius << std::endl;
        system("pause");
    }
    Circle(double x, double y, double r)
    {
        center.x = x;
        center.y = y;
        radius = r;
        std::cout << "---Construct a Circle object and set (x, y) = (" << center.x << ", " << center.y << ") and r = " << radius << std::endl;
        system("pause");
    }
    ~Circle()
    {
        delete &center;
        std::cout << "---Destruct a Circle object. " << std::endl;
        system("pause");
    }
    static bool intersect(const Circle &o1, const Circle &o2)
    {
        if (Point::dist(o1.center, o2.center) < o1.radius + o2.radius)
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
    delete &O1;
    delete &O2;
    return 0;
}
