#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    // 仓库选址
    while(T-- > 0){
        int n;
        cin >> n;
        ll px = 0, py = 0;
        vector<int> xs(n), ys(n);
        for(int i = 0; i < n; i++){
            cin >> xs[i] >> ys[i];
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        if(n % 2){
            cout << 1 << endl;
        }else{
            // 1 2 3 4
            px = xs[n / 2] - xs[(n - 1) / 2] + 1;
            py = ys[n / 2] - ys[(n - 1) / 2] + 1;
            cout << px * py << endl;
        }
    }

    return 0;
}
