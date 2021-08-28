#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

const int maxn = 5050;

int f[maxn][maxn];
// f[i][j]: 前i个人去匹配前j个空位的最小值
// f[i][j] =
//           min(f[i - 1][j - 1] + cost(i, j), f[i][j - 1]);
//

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(f, 0x3f, sizeof(f));

    int n;
    cin >> n;

    int a[n + 1];
    vector<int> people, seat;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i]){
            people.push_back(i);
        }else{
            seat.push_back(i);
        }
    }
    int n1 = people.size(), n2 = seat.size();

    for(int i = 0; i <= n2; i++){
        f[0][i] = 0;
    }
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            f[i][j] = min(f[i - 1][j - 1] + abs(people[i - 1] - seat[j - 1]), f[i][j - 1]);
        }
    }
    cout << f[n1][n2] << endl;
    return 0;
}
