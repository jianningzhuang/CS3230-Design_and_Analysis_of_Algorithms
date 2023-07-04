#include <iostream>
using namespace std;

int count_matches(const string &M, const string &N, int K) {
  int result = 0;
  int m = M.length();
  int n = N.length();
  for (int i = 0; i <= m-n; i++) {
    if (N.compare(M.substr(i, n)) == 0) {
      result++;
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
