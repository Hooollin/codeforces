#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool canForm(int n, int l, int r, int s){
    int minv, maxv;
    minv = (1 + r - l + 1) * (r - l + 1) / 2;
    maxv = (2 * n - (r - l)) * (r - l + 1) / 2;
    //cout << n << " " << l << " " << r << " " << s << minv << " " << maxv << endl;
    return s >= minv && s <= maxv;
}

int main(){
    int T;
    cin >> T;
    while(T-- > 0){
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        if(!canForm(n, l, r, s)){
            cout << -1 << endl;
            continue;
        }
        set<int> used;
        set<int> all;
        for(int i = 1; i <= n; i++){
            all.insert(i);
        }
        int now = n, i = r;
        while(s > 0){
            if(now < 0){
                break;
            }
            if(s >= now && canForm(now - 1, l, i - 1, s - now)){
                s -= now;
                used.insert(now);
                all.erase(now);
                i -= 1;
            }
            now -= 1;
        }
        for(int i = 1; i < l; i++){
            cout << *all.begin() << " ";
            all.erase(all.begin());
        }
        for(auto &v : used){
            cout << v << " ";
        }
        for(int i = r + 1; i <= n; i++){
            cout << *all.begin() << " ";
            all.erase(all.begin());
        }
        cout << endl;
    }
    
    return 0;
}
