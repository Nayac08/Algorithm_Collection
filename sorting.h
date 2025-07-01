#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>

using namespace std;

// Selection Sort - O(n^2)
template <typename T>
void selection_sort(vector<T> &A)
{
    size_t pos = A.size() - 1; // pos = next idx to be sorted
    for (; pos > 0; pos--)
    {
        int max_idx = -1;
        for (size_t i = 0; i <= pos; i++)
        {
            if (A[i] > A[max_idx])
                max_idx = i;
        }
        swap(A[pos], A[max_idx]);
    }
}

#endif // SORTING_H