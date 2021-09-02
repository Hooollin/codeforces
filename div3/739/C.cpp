#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;
  while(T-- > 0){
    int k;
    cin >> k;
    int circle = (int)floor(sqrt(k)), rem = k - circle * circle;
    if(rem == 0){
      cout << circle << " " << 1 << endl;
    }else{
      int curr = circle + 1;
      if(rem == curr){
        cout << curr <<  " " << curr << endl;
      }else if(rem < curr){
        cout << rem << " " << curr << endl;
      }else{
        cout << curr << " " << 2 * curr - rem << endl;
      }
    }
  }
  return 0;
}