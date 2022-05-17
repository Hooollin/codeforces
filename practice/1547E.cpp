#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[500050], ltemp[500050], rtemp[500050];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T-- > 0){
        memset(arr, 0x3f, sizeof(arr));
        memset(ltemp, 0x3f, sizeof(ltemp));
        memset(rtemp, 0x3f, sizeof(rtemp));

        int n, k;
        cin >> n >> k;
        vector<int> ai(k, 0);
        for(int i = 0; i < k; i++){
            cin >> ai[i];
        }
        for(int i = 0; i < k; i++){
            cin >> arr[ai[i]];
        }

        for(int i = 1; i <= n; i++){
            ltemp[i] = min(ltemp[i - 1] + 1, arr[i]);
        }
        for(int i = n; i >= 1; i--){
            rtemp[i] = min(rtemp[i + 1] + 1, arr[i]);
        }
        for(int i = 1; i <= n; i++){
            cout << min(ltemp[i], rtemp[i]) << " ";
        }
        cout << endl;
    }
    return 0;
}