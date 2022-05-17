#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<long long> f(n + 1), s(n + 1);
  f[1] = s[1] = 1;

  for(int i = 2; i <= n; i++){
    long long t = 0;
    for(int l = 2, r; l <= i; l = r + 1){
      r = i / (i / l);
      t += (r - l + 1) * f[i / l];
      t %= m;
    }
    f[i] = (s[i - 1] + t) % m;
    s[i] = (s[i - 1] + f[i]) % m;
  }
  cout << f[n] << endl;
  return 0;
}