#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> arr(3, 0);
  int T;
  cin >> T;
  while(T-- > 0) {
    for(int i = 0; i < 3; i++) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << arr[1] << endl;
  }
  return 0;
}
