#include <iostream>
using namespace std;

int count_matches(const string &M, const string &N, int K) {
  int result = 0;
  int m = M.length();
  int n = N.length();
  int p = 101;
  int offset = 1;
  for (int i = 0; i < n; i++) {
    offset = (offset*2)%p;
  }
  int hashp = 0;
  //unordered_map<int, int> wildcards;
  //int numwild = 0;
  int hasht = 0;
  for (int i = 0; i < n; i++) {
    hashp = (2*hashp + int(N[i] - '0'))%p;
    hasht = (2*hasht + int(M[i] - '0'))%p;
  }

  int i, j;
  for (i = 0; i <= m-n; i++) {
    if (hasht == hashp) {
      bool flag = true;
      for (j = 0; j < n; j++) {
        if (M[i+j] != N[j]) {
          flag = false;
          break;
        }
      }
      if (j == n) {
        result++;
      }
    }
    if (i < m-n) {
      hasht = (2*hasht - int(M[i] - '0')*offset + int(M[i+n] - '0'))%p;
      if (hasht < 0) {
        hasht = hasht + p;
      }
    }
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string M, N;
  int K;

  cin >> K >> M >> N;
  cout << count_matches(M, N, K) << endl;
}
