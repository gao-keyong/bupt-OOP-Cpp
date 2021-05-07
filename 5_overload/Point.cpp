#include <iostream>

class Point
{
public:
    Point() = default;
    Point(int x, int y) : x(x), y(y) {}
    friend std::ostream &operator<<(std::ostream &os, const Point &p)
    {
        os << '(' << p.x << ", " << p.y << ')';
        return os;
    }
    // 重载前置递增运算符++p
    Point &operator++()
    {
        ++x, ++y;
        return *this;
    }
    // 重载前置递减运算符--p
    Point &operator--()
    {
        --x, --y;
        return *this;
    }
    // 重载后置递增运算符p++
    const Point operator++(int)
    {
        Point ret = *this;
        ++*this;
        return ret;
    }
    // 重载后置递减运算符p--
    const Point operator--(int)
    {
        Point ret = *this;
        --*this;
        return ret;
    }
    ~Point() = default;

private:
    int x = 0, y = 0;
};

int main(int argc, char const *argv[])
{
    Point A, B(3, 5);
    std::cout << "A is " << A << std::endl;
    std::cout << "A++ *5: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << A++ << std::endl;
    }
    std::cout << "A is " << A << std::endl;
    std::cout << "A-- *5: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << A-- << std::endl;
    }
    std::cout << "A is " << A << std::endl;
    std::cout << "B is " << B << std::endl;
    std::cout << "--B *5: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << --B << std::endl;
    }
    std::cout << "B is " << B << std::endl;
    std::cout << "++B *5: " << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << ++B << std::endl;
    }
    std::cout << "B is " << B << std::endl;
    return 0;
}
