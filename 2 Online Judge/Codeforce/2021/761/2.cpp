#include<bits/stdc++.h>
using namespace std;
 

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int t;
 	cin >> t;
 	while (t--) {
 		long long n;
 		cin >> n;
 		if (n % 2 == 0) {
			cout << n - 3 << ' ' << 2 << ' ' << 1 << endl;
	
 		}
 		else {
			int a = n/2 + 1 ;
			int b = n/2 - 1 ;
			int c = 1;
			if (a % 2 == 0 && b % 2 == 0) {
				a++;
				b--;
			}
			cout << a << ' ' << b << ' ' << c << endl;
		}

 	}
    return 0;
}