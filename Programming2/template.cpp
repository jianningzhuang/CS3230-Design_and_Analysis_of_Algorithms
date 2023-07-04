#include <cmath>
#include <iostream>
using namespace std;

/*
 * Returns 0 if 2^a * 3^b = 2^c * 3^d
 *        -1 if 2^a * 3^b < 2^c * 3^d
 *         1 if 2^a * 3^b > 2^c * 3^d.
 *
 * This will run into precision issues for large a, b, c and d,
 * but for the range of values in this question this is OK.
 */
int compare(int a, int b, int c, int d) {
  if (a == c && b == d) return 0;
  if ((a - c) * log(2) + (b - d) * log(3) <= 0) return -1;
  return 1;
}

int count_ways(int m, int n) {
  // Write your code here!
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int a, b;

  cin >> a >> b;
  cout << count_ways(a, b) << endl;
}