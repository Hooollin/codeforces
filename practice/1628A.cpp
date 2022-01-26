#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 200050;
int vis[N], mex[N];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while(T-- > 0){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    memset(mex, 0, sizeof(mex));
    memset(vis, 0, sizeof(vis));

    int cur = 0;
    for(int i = n - 1; i >= 0; i--){
      vis[a[i]] = true;
      while(vis[cur]){
        cur++;
      }
      mex[i] = cur;
    }

    vector<int> ans;
    memset(vis, 0, sizeof(vis));

    int pos = 0;
    while(pos < n){
      ans.push_back(mex[pos]);     
      int j = pos;
      int cur = 0;
      while(j < n && cur < mex[pos]){
        vis[a[j]] = true;
        while(vis[cur]){
          cur++;
        }
        j++;
      }
      for(int i = pos; i < j; i++){
        vis[a[i]] = false;
      }
      pos = max(j, pos + 1);
    }
    cout << (int)ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++){
      cout << ans[i];
      if(i < (int)ans.size() - 1){
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}