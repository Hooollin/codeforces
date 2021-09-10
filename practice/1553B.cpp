#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while(T-- > 0){
    string s, t;
    cin >> s >> t;
    bool ans = false;
    for(int i = 0; i < (int)s.size(); i++){
      for(int r = 0; r < min((int)t.size(), (int)s.size() - i); r++){
        int l = (int)t.size() - r - 1;
        if(l > r + i){
          continue;
        }
        string a = s.substr(i, r + 1), b = s.substr(i + r - l, l);
        reverse(b.begin(), b.end());
        if(a + b == t){
          ans = true;
        }
      }
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}