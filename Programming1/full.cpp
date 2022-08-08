#include <bits/stdc++.h>
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
  for (int i = 0; i < n; i++) {
    hashp = (2*hashp + int(N[i] - '0'))%p;
  }

  int numwild = 0;
  int start = 0;
  int end = 0;
  while ((end - start) != n) {
    if (start > (m-n)) {
      return 0;
    }
    if (M[end] == '?') {
      numwild++;
      if (numwild > K) {
        while (M[start] != '?') {
          start++;
        }
        start++;
        numwild--;
      }
    }
    end++;
  }
  vector<int> wildcards = {0};

  for (int i = 0; i < n; i++) {
    vector<int> temp;
    bool flag = false;
    for (int j = 0; j < wildcards.size(); j++) {
      if (M[i+start] != '?') {
        wildcards[j] = (2*wildcards[j] + int(M[i+start] - '0'))%p;
      }
      else {
        flag = true;
        temp.push_back((2*wildcards[j] + 0)%p);
        temp.push_back((2*wildcards[j] + 1)%p);

      }
    }
    if (flag) {
      wildcards = temp;
    }
    flag = false;
  }

  int i, j, k;
  for (i = start; i <= m-n; i++) {
    //cout << "i = " << i << "size = " << wildcards.size() << endl;
    for (k = 0; k < wildcards.size(); k++) {
      if (wildcards[k] == hashp) {
        for (j = 0; j < n; j++) {
          if (M[i+j] != '?' && M[i+j] != N[j]) {
            break;
          }
        }
        if (j == n) {
          result++;
          break;
        }
      }
    }

    if (i < m-n) {
      if (M[i+n] != '?' && M[i] != '?') {
        for (k = 0; k < wildcards.size(); k++) {
          wildcards[k] = (2*wildcards[k] - int(M[i] - '0')*offset + int(M[i+n] - '0'))%p;
          if (wildcards[k] < 0) {
            wildcards[k] = wildcards[k] + p;
          }
        }
      }
      else if (M[i+n] != '?' && M[i] == '?') {
        vector<int> temp;
        for (k = 0; k < wildcards.size()/2; k++) {
          int temp1 = (2*wildcards[k] - int(k/pow(2,numwild-1))*offset + int(M[i+n] - '0'))%p;
          if (temp1 < 0) {
            temp1 = temp1 + p;
          }
          temp.push_back(temp1);
        }
        wildcards = temp;
        numwild--;
      }
      else if (M[i+n] == '?' && M[i] == '?') {
        vector<int> temp;
        for (k = 0; k < wildcards.size()/2; k++) {
          int temp1 = (2*wildcards[k] - int(k/pow(2,numwild-1))*offset + 0)%p;
          int temp2 = (2*wildcards[k] - int(k/pow(2,numwild-1))*offset + 1)%p;
          if (temp1 < 0) {
            temp1 = temp1 + p;
          }
          if (temp2 < 0) {
            temp2 = temp2 + p;
          }
          temp.push_back(temp1);
          temp.push_back(temp2);
        }
        wildcards = temp;
      }
      else if (M[i+n] == '?' && M[i] != '?') {
        numwild++;
        if (numwild <= K) {
          vector<int> temp;
          for (k = 0; k < wildcards.size(); k++) {
            int temp1 = (2*wildcards[k] - int(M[i] - '0')*offset + 0)%p;
            int temp2 = (2*wildcards[k] - int(M[i] - '0')*offset + 1)%p;
            if (temp1 < 0) {
              temp1 = temp1 + p;
            }
            if (temp2 < 0) {
              temp2 = temp2 + p;
            }
            temp.push_back(temp1);
            temp.push_back(temp2);
          }
          wildcards = temp;
        }
        else {
          int l = i+1;
          int r = i+n;
          while (numwild> K) {
            r++;
            if (M[r] == '?') {
              numwild++;
            }
            if (M[l] == '?') {
              numwild--;
            }
            l++;
            if (l > (m-n)) {
              return result;
            }
          }
          wildcards = {0};

          for (int a = 0; a < n; a++) {
            vector<int> temp;
            bool flag1 = false;
            for (int b = 0; b < wildcards.size(); b++) {
              if (M[a+l] != '?') {
                wildcards[b] = (2*wildcards[b] + int(M[a+l] - '0'))%p;
              }
              else {
                flag1 = true;
                temp.push_back((2*wildcards[b] + 0)%p);
                temp.push_back((2*wildcards[b] + 1)%p);

              }
            }
            if (flag1) {
              wildcards = temp;
            }
            flag1 = false;
          }
          i = l-1;
        }
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
