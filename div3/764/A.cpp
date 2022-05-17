#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int> arr;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    arr.push_back(x);
  }
  int maxv = *max_element(arr.begin(), arr.end());
  int minv = *min_element(arr.begin(), arr.end());
  cout << (maxv - minv) << endl;
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
