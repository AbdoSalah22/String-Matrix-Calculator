#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    string x;
    getline(cin, x);
    if (x[0] != '[')
    {
        cout << "ERROR!";
        return 0;
    }
    if (x[1] == ' ')
    {
        cout << "ERROR!";
        return 0;
    }
    if (x[x.length() - 1] != ']')
    {
        cout << "ERROR!";
        return 0;
    }

    x.erase(0, 1);
    x.pop_back();
    //cout << x << endl;

    string a1 = "";
    double mat1[100][100] = { 0 };
    double mat2[100][100] = { 0 };
    int rx = 0;
    int cx = 0;
    for (int i = 0;i <= x.length();i++)
    {
        if (x[i] == '-' || x[i] == '.' || x[i] || (x[i] >= '0' && x[i] <= '9'))
            a1 += x[i];

        if (x[i] == ' ')
        {
            mat1[rx][cx] = stod(a1);
            cx++;
            a1 = "";
        }

        if (i == x.length())
        {
            mat1[rx][cx] = stod(a1);
            cx++;
            a1 = "";
        }

        if (x[i] == ',')
        {
            mat1[rx][cx] = stod(a1);
            rx++;
            cx = 0;
            i++;
            a1 = "";
        }
    }

    int rows1 = 1;
    int columns1 = 1;
    rows1 += count(x.begin(), x.end(), ',');
    columns1 += count(x.begin(), x.end(), ' ');
    columns1 = columns1 / rows1;
    //cout << rows1 << columns1;

    char op;
    cin >> op;
    cin.ignore();
    switch (op)
    {
    case '+':
    {
        string y;
        getline(cin, y);
        if (y[0] != '[')
        {
            cout << "ERROR!";
            return 0;
        }
        if (y[y.length() - 1] != ']')
        {
            cout << "ERROR!";
            return 0;
        }

        y.erase(0, 1);
        y.pop_back();
        //cout << y << endl;

        string a2 = "";
        double mat2[100][100] = { 0 };
        int ry = 0;
        int cy = 0;
        for (int i = 0;i <= y.length();i++)
        {
            if (y[i] == '-' || y[i] == '.' || y[i] || (y[i] >= '0' && y[i] <= '9'))
                a2 += y[i];

            if (y[i] == ' ')
            {
                mat2[ry][cy] = stod(a2);
                cy++;
                a2 = "";
            }

            if (i == y.length())
            {
                mat2[ry][cy] = stod(a2);
                cy++;
                a2 = "";
            }

            if (y[i] == ',')
            {
                mat2[ry][cy] = stod(a2);
                ry++;
                cy = 0;
                i++;
                a2 = "";
            }
        }

        cout << '[';
        double mat3[100][100] = { 0 };
        for (int i = 0;i < rows1;i++)
        {
            for (int j = 0;j < columns1;j++)
            {
                if (!(j == 0 && i == 0))
                    cout << ' ';
                mat3[i][j] = mat1[i][j] + mat2[i][j];
                cout << mat3[i][j];

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
        getline(cin, y);
        if (y[0] != '[')
        {
            cout << "ERROR!";
            return 0;
        }
        if (y[y.length() - 1] != ']')
        {
            cout << "ERROR!";
            return 0;
        }

        y.erase(0, 1);
        y.pop_back();
        //cout << y << endl;

        string a2 = "";
        double mat2[100][100] = { 0 };
        int ry = 0;
        int cy = 0;
        for (int i = 0;i <= y.length();i++)
        {
            if (y[i] == '-' || y[i] == '.' || y[i] || (y[i] >= '0' && y[i] <= '9'))
                a2 += y[i];

            if (y[i] == ' ')
            {
                mat2[ry][cy] = stod(a2);
                cy++;
                a2 = "";
            }

            if (i == y.length())
            {
                mat2[ry][cy] = stod(a2);
                cy++;
                a2 = "";
            }

            if (y[i] == ',')
            {
                mat2[ry][cy] = stod(a2);
                ry++;
                cy = 0;
                i++;
                a2 = "";
            }
        }

        cout << '[';
        double mat3[100][100] = { 0 };
        for (int i = 0;i < rows1;i++)
        {
            for (int j = 0;j < columns1;j++)
            {
                if (!(j == 0 && i == 0))
                    cout << ' ';
                mat3[i][j] = mat1[i][j] - mat2[i][j];
                cout << mat3[i][j];

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
        getline(cin, y);
        if (y[0] != '[')
        {
            cout << "ERROR!";
            return 0;
        }
        if (y[y.length() - 1] != ']')
        {
            cout << "ERROR!";
            return 0;
        }

        y.erase(0, 1);
        y.pop_back();
        //cout << y << endl;

        string a2 = "";
        double mat2[100][100] = { 0 };
        int ry = 0;
        int cy = 0;
        for (int i = 0;i <= y.length();i++)
        {
            if (y[i] == '-' || y[i] == '.' || y[i] || (y[i] >= '0' && y[i] <= '9'))
                a2 += y[i];

            if (y[i] == ' ')
            {
                mat2[ry][cy] = stod(a2);
                cy++;
                a2 = "";
            }

            if (i == y.length())
            {
                mat2[ry][cy] = stod(a2);
                cy++;
                a2 = "";
            }

            if (y[i] == ',')
            {
                mat2[ry][cy] = stod(a2);
                ry++;
                cy = 0;
                i++;
                a2 = "";
            }
        }

        cout << '[';
        double mat3[100][100] = { 0 };
        for (int i = 0;i < rows1;i++)
        {
            for (int j = 0;j < columns1;j++)
            {
                if (!(j == 0 && i == 0))
                    cout << ' ';
                mat3[i][j] = mat1[i][j] - mat2[i][j];
                cout << mat3[i][j];

            }
            if (i != rows1 - 1)
                cout << ',';
        }
        cout << ']';
        break;
   
    }
        case 'T':
    {
        double transpose[100][100];
        for (int i = 0; i < rows1; ++i)
            for (int j = 0; j < columns1; ++j) {
                transpose[j][i] = mat1[i][j];
            }

        cout << '[';
        for (int i = 0; i < columns1; ++i)
            for (int j = 0; j < rows1; ++j) 
            {
                if (!(j == 0 && i == 0))
                    cout << ' ';
                cout << transpose[i][j];
                if (j == rows1-1 && i != columns1-1)
                    cout << ',';
            }
        cout << ']';
        break;
    }

        case 'D':
    {
        if(rows1!=columns1)
        {
            cout << "ERROR!";
            return 0;
        }
            double cx, detResult = 1;
            for (int i = 0; i < rows1; i++) {
                for (int k = i + 1; k < rows1; k++) {
                    cx = mat1[k][i] / mat1[i][i];
                    for (int j = i; j < rows1; j++)
                        mat1[k][j] = mat1[k][j] - cx * mat1[i][j];
                }
            }
            for (int i = 0; i < rows1; i++)
                detResult *= mat1[i][i];
            cout<< detResult;
            break;
    }

    //doesn't work properly
    case 'I':
    {
        double cx, detResult = 1;
        for (int i = 0; i < rows1; i++) {
            for (int k = i + 1; k < rows1; k++) {
                cx = mat1[k][i] / mat1[i][i];
                for (int j = i; j < rows1; j++)
                    mat1[k][j] = mat1[k][j] - cx * mat1[i][j];
            }
        }
        for (int i = 0; i < rows1; i++)
            detResult *= mat1[i][i];
        
        for (int i = 0; i < rows1; i++) 
        {
            for (int j = 0; j < rows1 ;j++)
                cout << ((mat1[(j + 1) % rows1][(i + 1) % rows1] * mat1[(j + 2) % rows1][(i + 2) % rows1]) 
                    - (mat1[(j + 1) % rows1][(i + 2) % rows1] * mat1[(j + 2) % rows1][(i + 1) % rows1])) / detResult;
        }
    }

    // default:
    // cout<<"Invalid Operand"<<endl;
    
    }

    return 0;
    //[1 2 3, 4 5 6, 7 8 9]
}