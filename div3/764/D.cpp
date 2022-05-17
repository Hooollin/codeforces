#include <iostream>

int cnt[26];

using namespace std;

void solve(){
  for(int i = 0; i < 26; i++){
    cnt[i] = 0;
  }
  int n, k;
  string s;
  cin >> n >> k >> s;
  
  for(auto &ch : s){
    cnt[ch - 'a']++;
  }

  int pairs = 0;
  int odd = 0;
  for(int i = 0; i < 26; i++){
    pairs += cnt[i] / 2;
    odd += cnt[i] % 2;
  }
  odd += pairs % k * 2;
  //cout << odd << " " << pairs << endl;
  int len = pairs / k * 2;
  if(odd >= k){
    len++;
  }
  cout << len << endl;
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