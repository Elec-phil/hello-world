#ifndef MATRIX_H_H
#define MATRIX_H_H
#include"iostream"
using namespace std;


class matrix
{

private:
    int r;
    int c;
    float **arr;
public:
// 缺省构造函数
    matrix();
// 带参数的构造函数
    matrix(int m,int n);
// 拷贝构造函数
    matrix(const matrix& a);
// 析构函数
    ~matrix();
    int getr()  {return r;}
    int getc()  {return c;}
// 重载加法
    matrix operator+(const  matrix& a);
// 重载减法
    matrix operator-(const  matrix& a);
// 重载矩阵相乘
    matrix operator*( const matrix& a);
// 重载矩阵数乘
    matrix operator*(float a);
// 重载=
    matrix& operator=( const matrix& a);
// 取矩阵元素()
    float operator()(int row, int col);
// 重载 <<
    friend ostream& operator<<(ostream& out, matrix& a);
// 重载 >>
    friend istream& operator>>(istream& in, matrix& a);
// 重载==
    bool operator!=(const matrix &a);
// 转置
    matrix operator~();
// 求行列式
    friend void getA(const matrix& a);
// 得到伴随矩阵
   friend void get_AJstart(matrix& a, float ajArr[][100]);
// 得到逆矩阵
   friend void get_inverse_start(matrix& a, float inv[][100]);

// 矩阵元素置零
    matrix& zero();

};

#endif
