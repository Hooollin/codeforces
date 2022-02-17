#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int freq[200050];
int cnt[200050];
bool reach[200050];

void solve(){
  memset(cnt, 0, sizeof(cnt));
  memset(reach, 0, sizeof(reach));
  memset(freq, 0, sizeof(freq));

  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    cnt[arr[i]]++;
    freq[arr[i]]++;
  }

  for(int i = 1; i <= n; i++){
    cnt[i] += cnt[i - 1];
  }

  reach[0] = cnt[0] > 0;
  for(int i = 1; i <= n; i++){
    if(cnt[i] > i && reach[i - 1]){
      reach[i] = true;
    }
  }

  sort(arr.begin(), arr.end());
  vector<long long> need(n + 1);
  priority_queue<int> q;
  int idx = 0;
  for(int i = 0; i <= n && reach[i]; i++){
    if(i > 0) need[i] = need[i - 1];
    while(idx < n && i > arr[idx]){
      q.push(arr[idx]);
      idx++;
    }
    if(freq[i] == 0){
      int v = q.top(); q.pop();
      //cout << "i, val: " << i << " " << v << endl;
      need[i] += i - v;
    }
    if(idx < n && i == arr[idx]){
      idx++;
    }
  }

  cout << cnt[0] << " ";
  for(int i = 1; i <= n; i++){
    if(reach[i - 1]){
      cout << freq[i] + need[i - 1] << " ";
    }else{
      cout << -1 << " ";
    }
  }
  cout << endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while(T-- > 0){
    solve();
  }

  return 0;
}