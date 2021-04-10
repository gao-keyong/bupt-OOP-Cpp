#include <iostream>
#include <cmath>

const double PI = M_PI;

class Shape
{
public:
    Shape()
    {
        std::cout << "---Construct an object of Shape" << std::endl;
        system("pause");
    }
    virtual double area() const = 0;
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
    double area() const override
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
    double area() const override
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
    delete pRec;
    delete pO;
    delete pSq;
    // Shape *pSh=new Shape();
    // 不允许上述定义，编译器报错“"message": "不允许使用抽象类类型 \"Shape\" 的对象: -- 函数 \"Shape::area\" 是纯虚拟函数",”
    return 0;
}

/*
> .\Shape.exe
---Construct an object of Shape
请按任意键继续. . . 
---Construct an object of Rectangle
请按任意键继续. . .
5
---Construct an object of Shape
请按任意键继续. . . 
---Construct an object of Circle
请按任意键继续. . . 
12.5664
---Construct an object of Shape
请按任意键继续. . . 
---Construct an object of Rectangle
请按任意键继续. . .
---Construct an object of Square
请按任意键继续. . .
40.96
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
*/
