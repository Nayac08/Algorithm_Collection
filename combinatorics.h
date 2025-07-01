#ifndef COMBINATORICS_H
#define COMBINATORICS_H

#include <iostream>
#include <vector>

using namespace std;

/*
Guideline
1. combination_nk -> nCk -- O(C(n, k) * n)
2. combination -> power set 2^n -- O(2^n * n)
3. permutation_nk -> nPk -- O(P(n, k) * k)
4. permutation -> n! -- O(n! * n)
5. permutaion_nk_replacement -> n^k -- O(n^k * k)
*/

// 1.combination of k items from n items
void combi_nk(int n, vector<int> &sol, int len, int k, int chosen,
              vector<vector<int>> &allSol)
{
  if (len < n)
  {
    if (len - chosen < n - k)
    {
      sol[len] = 0;
      combi_nk(n, sol, len + 1, k, chosen, allSol);
    }
    if (chosen < k)
    {
      sol[len] = 1;
      combi_nk(n, sol, len + 1, k, chosen + 1, allSol);
    }
  }
  else
  {
    allSol.push_back(sol);
  }
}

vector<vector<int>> combination_nk(int n, int k)
{
  vector<int> sol(n);
  vector<vector<int>> allSol;
  combi_nk(n, sol, 0, k, 0, allSol);
  return allSol;
}

// 2.combination of n items (powerset)
void combi(int n, vector<int> &sol, int len, vector<vector<int>> &allSol)
{
  if (len < n)
  {
    sol[len] = 0;
    combi(n, sol, len + 1, allSol);
    sol[len] = 1;
    combi(n, sol, len + 1, allSol);
  }
  else
  {
    allSol.push_back(sol);
  }
}

vector<vector<int>> combination(int n)
{
  vector<int> sol(n);
  vector<vector<int>> allSol;
  combi(n, sol, 0, allSol);
  return allSol;
}

// 3.permutation k items from n items
void permu_nk(int n, vector<int> &sol, int len, vector<bool> &used, int k, vector<vector<int>> &allSol)
{
  if (len < k)
  {
    for (int i = 0; i < n; i++)
    {
      if (used[i] == false)
      {
        used[i] = true;
        sol[len] = i;
        permu_nk(n, sol, len + 1, used, k, allSol);
        used[i] = false;
      }
    }
  }
  else
  {
    allSol.push_back(sol);
  }
}

vector<vector<int>> permutation_nk(int n, int k)
{
  vector<int> sol(k);
  vector<bool> used(n);
  vector<vector<int>> allSol;
  permu_nk(n, sol, 0, used, k, allSol);
  return allSol;
}

// 4.permutation n items
void permu(int n, vector<int> &sol, int len, vector<bool> &used, vector<vector<int>> &allSol)
{
  if (len < n)
  {
    for (int i = 0; i < n; i++)
    {
      if (used[i] == false)
      {
        used[i] = true;
        sol[len] = i;
        permu(n, sol, len + 1, used, allSol);
        used[i] = false;
      }
    }
  }
  else
  {
    allSol.push_back(sol);
  }
}

vector<vector<int>> permutation(int n)
{
  vector<int> sol(n);
  vector<bool> used(n);
  vector<vector<int>> allSol;
  permu(n, sol, 0, used, allSol);
  return allSol;
}

// 5.Permutaion k items from n items with replacement
void permu_nk_replacement(int n, vector<int> &sol, int len, int k, vector<vector<int>> &allSol)
{
  if (len < k)
  {
    for (int i = 0; i < n; i++)
    {
      sol[len] = i;
      permu_nk_replacement(n, sol, len + 1, k, allSol);
    }
  }
  else
  {
    allSol.push_back(sol);
  }
}

vector<vector<int>> permutation_nk_replacement(int n, int k)
{
  vector<int> sol(k);
  vector<vector<int>> allSol;
  permu_nk_replacement(n, sol, 0, k, allSol);
  return allSol;
}

#endif // COMBINATORICS_H