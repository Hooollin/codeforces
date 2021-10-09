#include <iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  while(tt-- > 0){
    int n;
    cin >> n;
    int c2 = n / 3, c1 = n / 3 + n % 3;
    int c22 = n / 3 + 1, c11 = n - 2 * (n / 3 + 1);
    if(abs(c2 - c1) <= abs(c22 - c11)){
      cout << c1 << " " << c2 << endl;
    }else{
      cout << c11 << " " << c22 << endl;
    }
  }
  return 0;
}
