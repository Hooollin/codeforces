#include <iostream>
#include <string>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  // 每个字母最多被paint 2次（红/绿）
  // 出现一次的字母只能和出现一次的字母配对
  // 出现两次的字母和自己配对

  int tt;
  cin >> tt;
  while(tt-- > 0){
    string s;
    cin >> s;
    int cnt[26];
    for(int i = 0; i < 26; i++){
      cnt[i] = 0;
    }
    int n = s.size();
    for(int i = 0; i < n; i++){
      cnt[s[i] - 'a']++;
      if(cnt[s[i] - 'a'] > 2){
        cnt[s[i] - 'a'] = 2;
      }
    }
    int odd_count = 0, even_count = 0;
    for(int i = 0; i < 26; i++){
      if(cnt[i] == 1){
        odd_count++;
      }else if(cnt[i] == 2){
        even_count++;
      }
    }
    cout << (even_count) + (odd_count) / 2 << endl;
  }

  return 0;
}