#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <vector>

using namespace std;

// Selection Sort - O(n^2) worst,best,avg
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

// Heap Sort - O(nlogn) worst,best,avg
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

// Insertion Sort - worst,avg O(n^2) best O(n)
template <typename T>
void insertion_sort(vector<T> &A)
{
    if (A.size() < 2)
        return;
    // pos = next idx to be sorted
    for (int pos = A.size() - 2; pos >= 0; pos--)
    {
        int i = pos + 1;
        T tmp = A[pos];
        while (i < A.size() && A[i] < tmp)
        {
            A[i - 1] = A[i];
            i++;
        } // find and sort simultaneously
        A[i - 1] = tmp;
    }
}

// Shell Sort
template <typename T>
void shell_sort(vector<T> &A, vector<int> gaps = {701, 301, 132, 57, 23, 10, 3, 1})
{
    for (int G : gaps)
    {
        // pos = next idx to be sorted within gap-based subarray
        for (int pos = A.size() - G - 1; pos >= 0; pos--)
        {
            T tmp = A[pos];
            int i = pos + G;

            while (i < A.size() && A[i] < tmp)
            {
                A[i - G] = A[i];
                i += G;
            }
            A[i - G] = tmp;
        }
    }
}

// Radix Sort - O(n)
int get_max_digit(vector<int> &A);
int get_digit(int x, int k);

void radix_sort(vector<int> &A)
{
    queue<int> q[10];
    int max_digit = get_max_digit(A);
    for (int i = 1; i <= max_digit; i++)
    {
        for (int &x : A)
        {
            q[get_digit(x, i)].push(x);
        }
        int idx = 0;
        for (int j = 0; j < 10; j++)
        {
            while (q[j].size() != 0)
            {
                A[idx++] = q[j].front();
                q[j].pop();
            }
        }
    }
}

int get_max_digit(const vector<int> &A)
{
    int max_digit = 1;
    for (int x : A)
    {
        int digits = 1;
        while (x >= 10)
        {
            x /= 10;
            digits++;
        }
        if (digits > max_digit)
            max_digit = digits;
    }
    return max_digit;
}

int get_digit(int x, int k)
{
    int r = 0;
    for (int i = 0; i < k; i++)
    {
        r = x % 10;
        x /= 10;
    }
    return r;
}

#endif // SORTING_H