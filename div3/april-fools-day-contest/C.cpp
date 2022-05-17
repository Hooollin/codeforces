#include <iostream>
#include <string>
using namespace std;

int main(){

    string str;
    cin >> str;
    int n = str.size();
    for(int i = 0; i < n - 2; i++){
        int a = str[i] - 'A', b = str[i + 1] - 'A', c = str[i + 2] - 'A';
        if((a + b) % 26 != c){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
