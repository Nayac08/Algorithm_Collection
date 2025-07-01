#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_1d_array(const vector<T> &A)
{
    if (A.empty())
        return;
    for (const T &a : A)
        cout << a << " ";
    cout << endl;
}

template <typename T>
void print_2d_array(const vector<vector<T>> &A)
{
    if (A.empty())
        return;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

#endif // UTILITIES_H