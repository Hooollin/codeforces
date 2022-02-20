#include <iostream>
#include <queue>

using namespace std;

void solve(){
  int n, m, k;
  cin >> n >> m >> k;

  int x = n % m;
  if(x == 0) x = m;
  int p = (n + m - 1) / m;
  int tot = p * x * k;
  int v = tot / n, extra = tot - n * v;
  //cout << x << " " << v << " " << extra << endl;
  //exit(-1);

  priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
  for(int i = 1; i <= extra; i++){
    q.push({v + 1, i});
  }
  for(int i = extra + 1; i <= n; i++){
    if(v > 0) q.push({v, i});
  }
  
  while(!q.empty()){
    vector<int> used(n + 1);
    for(int l = 0; l < x; l++){
      cout << p << " ";
      for(int i = 0; i < p; i++){
        auto [freq, now] = q.top(); q.pop();
        //cout << freq << " " << now << endl;
        used[now] = 1;
        if(freq > 1){
          q.push({now, freq - 1});
        }
        cout << now << " "; 
      }
      cout << endl;
    }
    for(int i = 0; i < m - x; i++){
      cout << (n / m) << " ";
      for(int i = 1; i <= n; i++){
        if(!used[i]){
          cout << i << " ";
        }
      }
      cout << endl;
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