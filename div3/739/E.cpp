#include <bits/stdc++.h>

using namespace std;

int cnt[26];
int need[26];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tt;
  cin >> tt;
  while(tt-- > 0){
    string t;
    cin >> t;
    memset(cnt, 0, sizeof(cnt));
    reverse(t.begin(), t.end());
    string seq;
    for(auto &ch : t){
      bool found = false;
      for(auto& s : seq){
        if(s == ch){
          found = true;
          break;
        }
      }
      if(!found){
        seq.push_back(ch);
      }
      cnt[ch - 'a']++;
    }
    reverse(t.begin(), t.end());
    bool valid = true;
    memset(need, 0, sizeof(need));
    for(int i = 0; i < (int)seq.size(); i++){
      if(cnt[seq[i] - 'a'] % ((int)seq.size() - i)){
        valid = false;
        break;
      }
      need[seq[i] - 'a'] = cnt[seq[i] - 'a'] / ((int)seq.size() - i);
    }
    if(!valid){
      cout << -1 << endl;
      continue;
    }
    reverse(seq.begin(), seq.end());
    int last = 0;
    for(int i = 0; i < 26;i++){
      last += need[i];
    }
    string ans = t.substr(0, last);
    set<char> removed;

    for(auto &ch : seq){
      removed.insert(ch);
      string temp;
      for(auto &c : ans){
        if(removed.find(c) == removed.end()){
          temp += c;
        }
      }
      if(t.substr(last, temp.size()) != temp){
        valid = false;
        break;
      }
      last += temp.size();
    }
    if(valid){
      cout << ans << " " << seq << endl;
    }else{
      cout << -1 << endl;
    }
  }
  return 0;
}