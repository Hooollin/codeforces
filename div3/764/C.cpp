#include <iostream>
#include <vector>

using namespace std;

int vis[55];

bool dfs(vector<int> &arr, int i){
  if(i == (int)arr.size()) return true;
  int val = arr[i];
  while(val > arr.size() || vis[val]){
    val /= 2;
  }
  if(val == 0 || vis[val]){
    return false;
  }
  vis[val] = true;
  if(dfs(arr, i + 1)){
    return true;
  }
  vis[val] = false;
  return false;
}

void solve(){
  for(int i = 0; i < 55; i++) vis[i] = 0;
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  if(dfs(arr, 0)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while(T-- > 0){
    solve();
  }

  return 0;
}