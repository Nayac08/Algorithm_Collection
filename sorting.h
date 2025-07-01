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
        // find max_idx
        int max_idx = -1;
        for (size_t i = 0; i <= pos; i++)
        {
            if (A[i] > A[max_idx])
                max_idx = i;
        }
        swap(A[pos], A[max_idx]); // sorted pos index with max_idx
    }
}

// Heap Sort - O(nlogn)
template <typename T>
void fix_down(vector<T> &A, int i, int size);

template <typename T>
void heap_sort(vector<T> &A)
{
    // build max heap - O(n)
    int n = A.size(); // n = size of heap not array
    for (int i = n / 2; i >= 0; i--)
    {
        fix_down(A, i, n);
    }
    // heap sort - O(nlogn)
    while (n > 1)
    {
        swap(A[0], A[n - 1]);
        n--; // reduce heap size
        fix_down(A, 0, n);
    }
}

template <typename T>
void fix_down(vector<T> &A, int i, int size)
{
    T tmp = A[i];
    int c;
    while ((c = 2 * i + 1) < size)
    {
        if (c + 1 < size && A[c] < A[c + 1])
            c++;
        if (A[c] < tmp)
            break;
        A[i] = A[c];
        i = c;
    }
    A[i] = tmp;
}

#endif // SORTING_H