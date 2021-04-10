#include <iostream>
#include <cmath>
#include <cstdlib>

const double PI = M_PI;

class Shape
{
public:
    Shape()
    {
        std::cout << "---Construct an object of Shape" << std::endl;
        system("pause");
    }
    double area();
    // 继承关系中根节点的类通常要定义一个虚析构函数
    virtual ~Shape()
    {
        std::cout << "---Destruct an object of Shape" << std::endl;
        system("pause");
    }
};

class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(double length, double width) : length(length), width(width)
    {
        std::cout << "---Construct an object of Rectangle" << std::endl;
        system("pause");
    }
    double area()
    {
        return length * width;
    }
    virtual ~Rectangle()
    {
        std::cout << "---Destruct an object of Rectangle" << std::endl;
        system("pause");
    }

protected:
    double length = 1.0;
    double width = 1.0;
};

class Circle : public Shape
{
public:
    Circle() = default;
    Circle(double radius) : radius(radius)
    {
        std::cout << "---Construct an object of Circle" << std::endl;
        system("pause");
    }
    double area()
    {
        return PI * radius * radius;
    }
    ~Circle()
    {
        std::cout << "---Destruct an object of Circle" << std::endl;
        system("pause");
    }

private:
    double radius = 1.0;
};

class Square : public Rectangle
{
public:
    Square() = default;
    Square(double length) : Rectangle(length, length)
    {
        std::cout << "---Construct an object of Square" << std::endl;
        system("pause");
    }
    ~Square()
    {
        std::cout << "---Destruct an object of Square" << std::endl;
        system("pause");
    }
};

int main(int argc, char const *argv[])
{
    Rectangle Rec(2.0, 2.5);
    std::cout << Rec.area() << std::endl;
    Circle O(2.0);
    std::cout << O.area() << std::endl;
    Square Sq(6.4);
    std::cout << Sq.area() << std::endl;
    return 0;
}

/* 输出信息为
> .\Shape.exe
---Construct an object of Shape
请按任意键继续. . . 
---Construct an object of Rectangle
请按任意键继续. . . 
// 以上是对对象Rec的调用
5
---Construct an object of Shape
请按任意键继续. . . 
---Construct an object of Circle
请按任意键继续. . . 
// 以上是对对象O的调用
12.5664
---Construct an object of Shape
请按任意键继续. . . 
---Construct an object of Rectangle
请按任意键继续. . . 
---Construct an object of Square
请按任意键继续. . . 
// 以上是对对象Sq的调用
40.96
---Destruct an object of Square
请按任意键继续. . . 
---Destruct an object of Rectangle
请按任意键继续. . . 
---Destruct an object of Shape
请按任意键继续. . .
// 删除了Sq对象
---Destruct an object of Circle
请按任意键继续. . .
---Destruct an object of Shape
请按任意键继续. . . 
// 删除了对象O
---Destruct an object of Rectangle
请按任意键继续. . . 
---Destruct an object of Shape
请按任意键继续. . . 
// 删除了对象Rec
// 对象构造函数的调用顺序是从基类到派生类依次调用，对象的析构函数的调用顺序是从派生类到基类依次调用

*/
