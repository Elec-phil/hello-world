#include"matrix.h"
#include"iostream"
#include"stdlib.h"
using namespace std;

matrix::matrix()
{
    r = 0;
    c = 0;
    arr = NULL;
}

 matrix::matrix(int m,int n)
{
        r = m;
        c = n;
        arr = new float*[r];
        for(int i=0;i<r;i++)
        arr[i] = new float[c];
}

matrix::matrix(const matrix& a)
{
        r = a.r;
        c = a.c;
        arr = new float*[r];
        for(int i=0;i<r;i++)
        arr[i] = new float[c];

        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        arr[i][j] = a.arr[i][j];
}

matrix::~matrix()
{
    if(arr != NULL)
    {
        for(int i=0;i<r;i++)
        delete[] arr[i];
        delete[] arr;
    }
}

matrix matrix::operator+(const  matrix& a)
{
        matrix temp(r,c);
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            temp.arr[i][j] = arr[i][j] + a.arr[i][j];
        return temp;
}

matrix matrix::operator-(const matrix& a)
{
      cout  << endl;
    if(r!=a.r || c!=a.c)
    {
        cout << "不合法！两个矩阵的行列应该相同 " << endl;
    }
    else
    {
        matrix temp(r,c);
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            temp.arr[i][j] = arr[i][j] - a.arr[i][j];
        return temp;
    }

      cout  << endl;
}

matrix matrix::operator*(const matrix &a)
{
    matrix temp(r,a.c);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<a.c;j++)
        {
            float sum=0;
            for(int m=0;m<c;m++)
            {
                sum = sum + arr[i][m] * a.arr[m][j];
            }
        temp.arr[i][j] = sum;
        }
    }
    return temp;

    cout  << endl;
}

matrix matrix::operator*(float a)
{
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    arr[i][j] = arr[i][j] * a;
    return *this;
}

matrix& matrix::operator=(const  matrix& a)
{
    if(this == &a)  return *this;

        r = a.r;
        c = a.c;
        arr = new float*[r];
        for(int i=0;i<r;i++)
        arr[i] = new float[c];

        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        arr[i][j] = a.arr[i][j];
        return *this;

}

/*
 float matrix::operator()(int row, int col)
 {
     cout << "Start with (0,0)" << endl;
     if(row>r-1 || col>c-1)     cout << "Invalid! out of range." << endl;
     else       return arr[row][col];
 }
*/


// ÖØÔØcout<<
ostream& operator<<(ostream& out, matrix& a)
{
    for(int i=0;i<a.r;i++)
        {
              for(int j=0;j<a.c;j++)
              cout<< a.arr[i][j] << " ";
          cout << endl;
        }
    return out;
}

istream& operator>>(istream& in, matrix& a)
{
    cout << "Input the elements: " << endl;
    for(int i=0;i<a.r;i++)
    for(int j=0;j<a.c;j++)
    cin >> a.arr[i][j];
    return in;
}

bool matrix::operator!=(const matrix &a)
{
    if(r!=a.r)  return true;
    if(c!=a.c)  return true;
    for(int i=0;i<r;i++)
    for(int j=0;j<r;j++)
        if(arr[i][j]!=a.arr[i][j])  return true;

    return false;

}

// 矩阵元素置零
/*
matrix& matrix::zero()
{
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    arr[i][j] = 0;
    return *this;
}


// 转置
matrix matrix::operator~()
{
    matrix temp(c,r);
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    {
        temp.arr[j][i] = arr[i][j];
    }
    return temp;
}

*/



// geta() 函数声明
float geta(float arr[][100], int n);

// 友元 getA（） 显示行列式的值
void getA(const matrix& a)
{
    int n = a.r;
    if( n>100 || n<=0 )
    {
        cout << "Invalid! (0 < the dimension of the matrix <= 100) " << endl;
    }
    else if( a.r != a.c)
    {
        cout << "Invalid! The row and col of matrix should be the same " << endl;
    }
    else
    {
        float arrTemp[100][100] = {0};
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        arrTemp[i][j] = a.arr[i][j];

        cout <<  geta(arrTemp,n);

    }//else
}


// geta（）函数定义  求行列式的值
float geta(float arr[][100], int n)
{
    if( n==1 )  return arr[0][0];

    int i,j,k;
    float sum = 0;
    float temp[100][100] = {0};
    for( i=0;i<n;i++)
    {
        for( j=0;j<n-1;j++)
        for( k=0;k<n-1;k++)
        temp[j][k] = arr[j+1][(k>=i) ? k+1 : k ];

      float t = geta(temp,n-1);
      if(i%2 == 0)    sum = sum + arr[0][i] * t;
      else            sum = sum - arr[0][i] * t;
    }
    return sum;
}

// get_AJmatrix() 声明
void get_AJmatrix(float arr[][100], int n, float ajArr[][100]);

// get_AJstart() 友元定义
void get_AJstart(matrix& a, float aj[][100])
{
    int n = a.r;
    float temp[100][100]={0};
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    temp[i][j] = a.arr[i][j];

    get_AJmatrix(temp, n, aj);

    for(int i=0;i<n;i++)
    {
           for(int j=0;j<n;j++)
           cout << aj[i][j] << " " ;
        cout << endl;
    }

    cout << "AJstart() end" << endl;

}

void get_AJmatrix(float arr[][100], int n, float ajArr[][100])
{
    if(n == 1)
    {
        ajArr[0][0] = 1;
        return ;
    }
    int i,j,k,t;
    float temp[100][100];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n-1;k++)
            {
                for(t=0;t<n-1;t++)
                {
                    temp[k][t] = arr[ (k>=i) ? k+1 : k][ (t>=j) ? t+1 : t];
                }
            }

            ajArr[j][i] = geta(temp,n-1);

            if( (i+j)%2 == 1)  ajArr[j][i] = - ajArr[j][i];

        }
    }
}

// get_inverse() 声明
void get_inverse(float arr[][100], int n, float inv[][100]);


void get_inverse_start(matrix& a, float inv[][100])
{
    int n = a.r;
    float temp[100][100]={0};
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    temp[i][j] = a.arr[i][j];

    get_inverse(temp, n, inv);

}


void get_inverse(float arr[][100], int n, float inv[][100])
{
    float flag = geta(arr,n);
    float aj[100][100] = {0};

    if(flag == 0)  cout << "Invalid! The value of martix is 0 " << endl;
    else
    {
        get_AJmatrix(arr, n, aj);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            inv[i][j] = aj[i][j] / flag;

    cout << "result of inv: " << endl;
         for(int i=0;i<n;i++)
        {
             for(int j=0;j<n;j++)
             cout << inv[i][j] << " " ;
           cout<<endl;
        }

    }// else

}





