#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T-- > 0){
        long long n;
        cin >> n;
        if(n % 2) n++;
        n = max(1LL * 6, n);
        cout << n * 5 / 2 << endl;
    }
    return 0;
}

