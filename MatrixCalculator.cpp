#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>

#define N 100

using namespace std;
//[1 2 3, 4 5 6, 7 8 9]
//[1 4 7, 2 5 8, 3 6 9]

void readMatrix(string &input, double mat[N][N])
{
    if (input[0] != '[')
    {
        cout << "ERROR!";
        exit(0);
    }
    if (input[1] == ' ')
    {
        cout << "ERROR!";
        exit(0);
    }
    if (input[input.length() - 1] != ']')
    {
        cout << "ERROR!";
        exit(0);
    }

    input.erase(0, 1);
    input.pop_back();

    string num = "";
    int rx = 0;
    int cx = 0;
    for (int i = 0; i <= input.length(); i++)
    {
        if (input[i] == '-' || input[i] == '.' || input[i] || (input[i] >= '0' && input[i] <= '9'))
            num += input[i];

        if (input[i] == ' ')
        {
            mat[rx][cx] = stod(num);
            cx++;
            num = "";
        }

        if (i == input.length())
        {
            mat[rx][cx] = stod(num);
            cx++;
            num = "";
        }

        if (input[i] == ',')
        {
            mat[rx][cx] = stod(num);
            rx++;
            cx = 0;
            i++;
            num = "";
        }
    }
}

int calcRows(string &s)
{
    int rows = 1;
    rows += count(s.begin(), s.end(), ',');
    return rows;
}

int calcCols(string &s, int rows)
{
    int cols = 1;
    cols += count(s.begin(), s.end(), ' ');
    cols = cols / rows;
    return cols;
}

int main()
{
    string x;
    double mat1[N][N] = {0};
    char op;

    getline(cin, x);
    readMatrix(x, mat1);
    int rows1 = calcRows(x);
    int cols1 = calcCols(x, rows1);

    cin >> op;
    cin.ignore();

    switch (op)
    {
    case '+':
    {
        string y;
        double mat2[N][N] = {0};
        getline(cin, y);
        readMatrix(y, mat2);
        int rows2 = calcRows(y);
        int cols2 = calcCols(y, rows2);

        if (rows1 != rows2 || cols1 != cols2) {
            cout << "ERROR!";
            exit(0);
        }
        cout << '[';
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols1; j++)
            {
                if (!(j == 0 && i == 0))
                    cout << ' ';
                cout << (int)((mat1[i][j] + mat2[i][j])*100) / 100.0;
            }
            if (i != rows1 - 1)
                cout << ',';
        }
        cout << ']';
        break;
    }

    case '-':
    {
        string y;
        double mat2[N][N] = {0};
        getline(cin, y);
        readMatrix(y, mat2);
        int rows2 = calcRows(y);
        int cols2 = calcCols(y, rows2);

        if (rows1 != rows2 || cols1 != cols2) {
            cout << "ERROR!";
            exit(0);
        }

        cout << '[';
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols1; j++)
            {
                if (!(j == 0 && i == 0))
                    cout << ' ';
                cout << (int)((mat1[i][j] - mat2[i][j])*100) / 100.0;
            }
            if (i != rows1 - 1)
                cout << ',';
        }
        cout << ']';
        break;
    }

    case '*':
    {
        string y;
        double mat2[N][N] = {0};
        getline(cin, y);
        readMatrix(y, mat2);
        int rows2 = calcRows(y);
        int cols2 = calcCols(y, rows2);

        if (cols1 != rows2) {
            cout << "ERROR!";
            exit(0);
        }

        double temp;
        cout << '[';
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < cols2; j++) {
                if (!(j == 0 && i == 0)) {
                    cout << ' ';
                }
                temp = 0;
                for (int k = 0; k < cols1; k++) {
                    temp += mat1[i][k] * mat2[k][j];
                }
                cout << (int)((temp)*100) / 100.0;
            }
            if (i != rows1 - 1) {
                cout << ',';
            }
        }
        cout << ']';
        break;
    }

    case 'T':
    {
        cout << '[';
        for (int i = 0; i < cols1; ++i)
            for (int j = 0; j < rows1; ++j)
            {
                if (!(j == 0 && i == 0))
                    cout << ' ';
                cout << mat1[j][i];
                if (j == rows1 - 1 && i != cols1 - 1)
                    cout << ',';
            }
        cout << ']';
        break;
    }

    case 'D':
    {
        if (rows1 != cols1){
            cout << "ERROR!";
            return 0;
        }
        double cx, detResult = 1;
        for (int i = 0; i < rows1; i++){
            if (mat1[i][i] == 0) {
                cout << "ERROR!";
                exit(0);
            }

            for (int k = i + 1; k < rows1; k++){
                cx = mat1[k][i] / mat1[i][i];
                for (int j = i; j < rows1; j++)
                    mat1[k][j] = mat1[k][j] - cx * mat1[i][j];
            }
        }
        for (int i = 0; i < rows1; i++)
            detResult *= mat1[i][i];
        cout << detResult;
        break;
    }

        // needs fixing
         case 'I':
         {
            if (rows1 != cols1){
                cout << "ERROR!";
                return 0;
            }
            double cx, detResult = 1;
            for (int i = 0; i < rows1; i++){
                if (mat1[i][i] == 0) {
                    cout << "ERROR!";
                    exit(0);
                }

                for (int k = i + 1; k < rows1; k++){
                    cx = mat1[k][i] / mat1[i][i];
                    for (int j = i; j < rows1; j++)
                        mat1[k][j] = mat1[k][j] - cx * mat1[i][j];
                }
            }
            for (int i = 0; i < rows1; i++)
                detResult *= mat1[i][i];

            if (detResult == 0) {
                cout << "ERROR!";
                exit(0);
            }

            cout << '[';
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < rows1; j++) {
                    if (!(j == 0 && i == 0))
                        cout << ' ';
                    double cofactor = ((mat1[(j + 1) % rows1][(i + 1) % rows1] * mat1[(j + 2) % rows1][(i + 2) % rows1]) -
                                    (mat1[(j + 1) % rows1][(i + 2) % rows1] * mat1[(j + 2) % rows1][(i + 1) % rows1]));
                    cout << cofactor / detResult;
                }
                if (i != rows1 - 1)
                    cout << ',';
            }
            cout << ']';
        }

        default:
        ;
        // cout<<"Invalid Operand"<<endl;
    }

    return 0;
}