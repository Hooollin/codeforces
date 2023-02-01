#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> lines;
  for(int i = 0; i < n; i += 1) {
    vector<int> line;
    for(int k = 0; k < n - 1; k += 1) {
      int v;
      cin >> v;
      line.push_back(v);
    }
    lines.push_back(line);
  }

  vector<int> ans(n, -1);
  for(int target = 1; target <= n; target += 1) {
    set<int> st;
    for(auto &line : lines) {
      bool found = false;
      for(int i = 0; i < (int)line.size(); i += 1) {
        if(found) {
          st.insert(line[i]);
        }
        if(line[i] == target) {
          found = true;
        }
      }
    }
    //cout << "DEBUG: " << st.size() << " " << endl;
    ans[n - 1 - (int)st.size()] = target;
  }
  for(int i = 0; i < n; i += 1) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;

  while(T-- > 0) {
    solve();
  }

  return 0;
}
