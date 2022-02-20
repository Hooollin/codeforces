#include <iostream>
#include <queue>

using namespace std;

void solve(){
  int n, m, k;
  cin >> n >> m >> k;

  int x = n % m;
  if(x == 0) x = m;
  int p = (n + m - 1) / m;
  //cout << x << " " << v << " " << extra << endl;
  //exit(-1);

  int b = 0;
  for(int round = 0; round < k; round++){
    for(int l = 0; l < x; l++){
      cout << p << " ";
      for(int i = 0; i < p; i++){
        cout << (i + b) % n + 1 << " ";
      }
      b += p;
      b %= n;
      cout << endl;
    }
    for(int i = 0; i < m - x; i++){
      int small = n / m;
      cout << small << " ";
      for(int j = 0; j < small; j++){
        cout << ((b + j + i * small) % n + 1) << " ";
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