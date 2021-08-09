#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while(T-- > 0){
    string s, t;
    cin >> s >> t;
    int m = s.size(), n = t.size();
    int i = m - 1, j = n - 1;
    while(i >= 0 && j >= 0){
      if(s[i] == t[j]){
        i--;
        j--;
      }else{
        i -= 2;
      }
    }
    std::cout << (j == -1 ? "YES" : "NO") << endl;
  }
  return 0;
}