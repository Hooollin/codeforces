#include <iostream>

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
    int now = 1;
    for(;;){
      if(!(now % 3 == 0 || (now % 10) == 3)){
        k--;
      }
      if(k == 0){
        break;
      }
      now++;
    }
    cout << now << endl;
  }

  return 0;
}