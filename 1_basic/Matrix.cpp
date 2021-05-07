#include <iostream>

const size_t ROW = 4;
const size_t COLUMN = 5;

class Matrix
{
public:
    Matrix()
    {
        mat = new int *[ROW];
        for (int i = 0; i < ROW; i++)
        {
            mat[i] = new int[COLUMN];
            for (int j = 0; j < COLUMN; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < ROW; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }
    int *operator[](const int idx) const
    {
        return mat[idx];
    }
    const Matrix operator+(const Matrix &rhs)
    {
        Matrix res;
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUMN; j++)
            {
                res[i][j] = this->mat[i][j] + rhs.mat[i][j];
            }
        }
        return res;
    }
    const Matrix operator-(const Matrix &rhs)
    {
        Matrix res;
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUMN; j++)
            {
                res[i][j] = this->mat[i][j] - rhs.mat[i][j];
            }
        }
        return res;
    }
    void init()
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUMN; j++)
            {
                std::cin >> mat[i][j];
            }
        }
    }
    void print()
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUMN; j++)
            {
                std::cout << mat[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

private:
    int **mat;
};

int main(int argc, char const *argv[])
{
    Matrix *A1 = new Matrix(), *A2 = new Matrix(), *A3 = new Matrix;
    std::cout << "Input A1: " << std::endl;
    A1->init();
    std::cout << "Input A2: " << std::endl;
    A2->init();
    *A3 = *A1 + *A2;
    std::cout << "A3 = A1 + A2 = " << std::endl;
    A3->print();
    *A3 = *A1 - *A2;
    std::cout << "A3 = A1 - A2 = " << std::endl;
    A3->print();
    return 0;
}
