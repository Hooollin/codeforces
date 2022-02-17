#include <iostream>
#include <set>
#include <cmath>

using namespace std;

void solve(){
  int n;
  cin >> n;

  set<int> seen;
  for(int i = 1; i <= sqrt(n); i++){
    if(seen.find(i * i) == seen.end()){
      seen.insert(i * i);
    }
    long long a = (long long)i * i * i;
    if(a <= n && seen.find(a) == seen.end()){
      seen.insert(a);
    }
  }
  cout << seen.size() << endl;
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