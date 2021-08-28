#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while(T-- > 0){
		int l, r;
		cin >> l >> r;
		int a[10], b[10];
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int k = 0;
		while(r){
			int ld = l % 10, rd = r % 10;
			b[k] = ld, a[k] = rd;
			l /= 10;
			r /= 10;
			k++;
		}

		long long ans = 0, base = 1, carry = 0;
		for(int i = 0; i < k; i++){
			if(a[i] + carry < b[i]){
				a[i] = a[i] + 10 - b[i] + carry;
				carry = -1;
			}else{
				a[i] = a[i] - b[i];
				carry = 0;
			}
		}
		for(int i = 0; i < k; i++){
			ans += base * a[i];
			base *= 10;
		}
		cout << ans << endl;
	}
	return 0;
}