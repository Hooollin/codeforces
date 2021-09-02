#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;
  while(T-- > 0){
    int a, b, c;
    cin >> a >> b >> c;
    int r = abs(a - b);
    if(c > 2 * r || 2 * r < max(a, b)){
      cout << -1 << endl;
    }else{
      if(c <= r){
        cout << c + r << endl;
      }else{
        cout << c - r << endl;
      }
    }
  }
  return 0;
}