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
    double area() const
    {
        return 0.;
    }
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
    double area() const
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
    double area() const
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
    Shape *pRec = new Rectangle(2.0, 2.5);
    std::cout << pRec->area() << std::endl;
    Shape *pO = new Circle(2.0);
    std::cout << pO->area() << std::endl;
    Shape *pSq = new Square(6.4);
    std::cout << pSq->area() << std::endl;
    Shape *pSh = new Shape();
    // 上述语句这样的定义能通过编译，但显然毫无意义，应当将Shape定义为抽象基类，不允许定义类型为Shape的对象
    delete pRec;
    delete pO;
    delete pSq;
    delete pSh;
    return 0;
}

/*
我们看到，所有指针的静态类型为Shape *，动态类型为各自派生类对象的指针类型，在编译时，所有调用的area函数都绑定到了
Shape类型对应的函数area，从而输入全部为0，未能正确计算。
而如果把基类函数定义为基函数，则函数调用会根据动态类型在运行时绑定对应的派生类的函数，从而正确计算出指针所指对象的
面积，参见程序5_overload/Shape.cpp
> .\Shape_A.exe
---Construct an object of Shape
请按任意键继续. . . 
---Construct an object of Rectangle
请按任意键继续. . .
0
---Construct an object of Shape
请按任意键继续. . . 
---Construct an object of Circle
请按任意键继续. . .
0
---Construct an object of Shape
请按任意键继续. . .
---Construct an object of Rectangle
请按任意键继续. . .
---Construct an object of Square
请按任意键继续. . . 
0
---Construct an object of Shape
请按任意键继续. . . 
---Destruct an object of Rectangle
请按任意键继续. . . 
---Destruct an object of Shape
请按任意键继续. . . 
---Destruct an object of Circle
请按任意键继续. . .
---Destruct an object of Shape
请按任意键继续. . .
---Destruct an object of Square
请按任意键继续. . .
---Destruct an object of Rectangle
请按任意键继续. . . 
---Destruct an object of Shape
请按任意键继续. . .
---Destruct an object of Shape
请按任意键继续. . . 
*/