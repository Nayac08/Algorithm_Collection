#include <iostream>
#include <vector>

using namespace std;

/*
Guideline
1. combination_nk -> nCk
2. combination -> power set 2^n
3. permutation_nk -> nPk
4. permutation -> n!
5. permutaion_nk_replacement -> n^k
*/

// 1.combination of k items from n items
void combi_nk(int n, vector<int> &sol, int len, int k, int chosen,
              vector<vector<int>> &allSol) {
  if (len < n) {
    if (len - chosen < n - k) {
      sol[len] = 0;
      combi_nk(n, sol, len + 1, k, chosen, allSol);
    }
    if (chosen < k) {
      sol[len] = 1;
      combi_nk(n, sol, len + 1, k, chosen + 1, allSol);
    }
  } else {
    allSol.push_back(sol);
  }
}

vector<vector<int>> combination_nk(int n, int k) {
  vector<int> sol(n);
  vector<vector<int>> allSol;
  combi_nk(n, sol, 0, k, 0, allSol);
  return allSol;
}

// 2.combination of n items (powerset)
void combi(int n, vector<int> &sol, int len, vector<vector<int>> &allSol) {
  if (len < n) {
    sol[len] = 0;
    combi(n, sol, len + 1, allSol);
    sol[len] = 1;
    combi(n, sol, len + 1, allSol);
  } else {
    allSol.push_back(sol);
  }
}

vector<vector<int>> combination(int n) {
  vector<int> sol(n);
  vector<vector<int>> allSol;
  combi(n, sol, 0, allSol);
  return allSol;
}

int main() {
  combination(5);
  return 0;
}