#include <iostream>
#include <vector>

using namespace std;

const int maxn = (int)2e5 + 50;

vector<int> a(maxn), b(maxn);

long long get(int a, int b){
    if(a % b == 0){
        return a / b;
    }
    return a / b + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T-- > 0){
        long long n, c;
        cin >> n >> c;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n - 1; i++){
            cin >> b[i];
        }
        b.push_back(0);       
        long long ans = (long long)1e18;
        long long have = 0;
        long long day = 0;
        for(int i = 0; i < n; i++){
            long long earn = a[i], need = b[i];
            ans = min(ans, day + get(c - have, earn));
            if(have >= need){
                have -= need;
                day += 1;
            }else{
                long long workday = get(need - have, earn);
                day += workday + 1;
                have = have + workday * earn - need;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
