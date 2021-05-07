#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>

// 检查输入的一行是否为1到1000之间的数字
bool isValid(const std::string &buf)
{
    if (buf.length() > 4) // 输入太长，不合法
        return false;
    for (auto c : buf) //输入中含有非数字值，不合法
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    int usrAns;
    std::istringstream usrAnsStream(buf);
    usrAnsStream >> usrAns;
    if (usrAns < 1 || usrAns > 1000) // 数字不在1到1000之间，不合法
        return false;
    return true;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int realAns = rand() % 1000 + 1;
    std::cout << realAns << std::endl;
    do
    {
        int usrAns;
        std::string usrAnsBuf;
        std::cout << "Your answer: ";
        std::getline(std::cin, usrAnsBuf); // 将一行放在string缓冲区里面
        // 处理不合法的输入
        if (!isValid(usrAnsBuf))
        {
            std::cout << "Not a number or out of bound. Try again! " << std::endl;
            continue;
        }
        std::istringstream usrAnsStream(usrAnsBuf);
        usrAnsStream >> usrAns;
        // 猜错的情况下
        if (usrAns != realAns)
        {
            std::cout << "Oops! " << usrAns << " is too ";
            if (usrAns < realAns)
            {
                std::cout << "LOW";
            }
            else
            {
                std::cout << "HIGH";
            }
            std::cout << ". Try again! " << std::endl;
        }
        else
            break; // 猜对的情况下
    } while (true);
    std::cout << "Bingo! " << std::endl;
    return 0;
}
