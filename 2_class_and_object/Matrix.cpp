#include <iostream>

template <class T>
class Matrix
{
public:
    Matrix() = default;
    Matrix(size_t row, size_t column)
    {
        this->row = row;
        this->column = column;
        p = new T *[row];
        for (size_t i = 0; i < row; i++)
        {
            p[i] = new T[column];
        }
    }
    Matrix(const Matrix &o)
    {
        this->row = o.row;
        this->column = o.column;
        p = new T *[row];
        for (size_t i = 0; i < row; i++)
        {
            p[i] = new T[column];
            for (size_t j = 0; j < column; j++)
            {
                p[i][j] = o.p[i][j];
            }
        }
    }
    ~Matrix()
    {
        for (size_t i = 0; i < row; i++)
        {
            delete[] p[i];
        }
        delete[] p;
    }
    // make operator overloading function a friend of the class
    // because it would be called without creating an object.
    friend std::ostream &operator<<(std::ostream &output, const Matrix &o)
    {
        for (size_t i = 0; i < o.row; i++)
        {
            for (size_t j = 0; j < o.column; j++)
            {
                output << o.p[i][j] << ' ';
            }
            output << std::endl;
        }
        return output;
    }
    friend std::istream &operator>>(std::istream &input, Matrix &o)
    {
        for (size_t i = 0; i < o.row; i++)
        {
            for (size_t j = 0; j < o.column; j++)
            {
                input >> o.p[i][j];
            }
        }
        return input;
    }
    T *operator[](const size_t idx)
    {
        return p[idx];
    }
    Matrix operator+(const Matrix &o)
    {
        if (this->row != o.row || this->column != o.column)
        {
            throw "Dimension Error";
        }
        Matrix res(o);
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < column; j++)
            {
                res.p[i][j] += this->p[i][j];
            }
        }
        return res;
    }
    Matrix operator-(const Matrix &o)
    {
        if (this->row != o.row || this->column != o.column)
        {
            throw "Dimension Error";
        }
        Matrix res(*this);
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < column; j++)
            {
                res[i][j] -= o.p[i][j];
            }
        }
        return res;
    }
    Matrix &operator=(const Matrix &rhs)
    {
        if (this == &rhs)
        { // guard against self-assignment
            return *this;
        }
        row = rhs.row;
        column = rhs.column;
        T **pOld = p;
        p = new T *[row];
        for (size_t i = 0; i < row; i++)
        {
            p[i] = new T[column];
            for (size_t j = 0; j < column; j++)
            {
                p[i][j] = rhs.p[i][j];
            }
        }
        // release old element
        for (size_t i = 0; i < row; i++)
        {
            delete[] pOld[i];
        }
        delete[] pOld;
        return *this;
    }

private:
    T **p;
    size_t row, column;
};

int main(int argc, char const *argv[])
{
    size_t n, m;
    std::cout << "---Objects in stack: " << std::endl;
    std::cout << "Input the numbers of rows and columns of A1, A2 and A3: " << std::endl;
    std::cin >> n >> m;
    Matrix<int> A1(n, m), A2(n, m), A3(n, m);
    std::cout << "Input A1: " << std::endl;
    std::cin >> A1;
    std::cout << "Input A2: " << std::endl;
    std::cin >> A2;
    A3 = A1 + A2;
    std::cout << "A3 = A1 + A2 = " << std::endl
              << A3;
    A3 = A1 - A2;
    std::cout << "A3 = A1 - A2 = " << std::endl
              << A3;
    std::cout << "---Objects in heap: " << std::endl;
    std::cout << "Input the numbers of rows and columns of pA1, pA2 and pA3: " << std::endl;
    std::cin >> n >> m;
    Matrix<int> *pA1 = new Matrix<int>(n, m);
    Matrix<int> *pA2 = new Matrix<int>(n, m);
    Matrix<int> *pA3 = new Matrix<int>(n, m);
    std::cout << "Input pA1: " << std::endl;
    std::cin >> *pA1;
    std::cout << "Input pA2: " << std::endl;
    std::cin >> *pA2;
    *pA3 = *pA1 + *pA2;
    std::cout << "pA3 = pA1 + pA2 = " << std::endl
              << *pA3;
    *pA3 = *pA1 - *pA2;
    std::cout << "pA3 = pA1 - pA2 = " << std::endl
              << *pA3;
    delete pA1,pA2,pA3;
    return 0;
}
