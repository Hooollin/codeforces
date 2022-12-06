#include <bits/stdc++.h>

using namespace std;

int dfs(vector<int> &A, int i, int a, int b, long long p) {
  if(i == A.size()) {
    return i;
  }
  if(A[i] < p) {
    return dfs(A, i + 1, a, b, p + A[i] / 2);
  }
  int ans = i;
  if(a > 0) {
    ans = max(ans, dfs(A, i, a - 1, b, p * 2));
  }
  if(b > 0) {
    ans = max(ans, dfs(A, i, a, b - 1, p * 3));
  }
  return ans;
}

void solve() {
  int n, h;
  cin >> n >> h;
  
  vector<int> A;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  sort(A.begin(), A.end());

  cout << dfs(A, 0, 2, 1, h) << endl;
}

int main() {
  int T;
  cin >> T;

  while(T-- > 0) {
    solve();
  }
  return 0;
}
