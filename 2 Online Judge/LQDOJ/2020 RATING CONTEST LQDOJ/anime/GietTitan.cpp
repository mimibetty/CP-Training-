#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
    	long long m,n;
	 	cin >> n >> m;
	 	if (m > n/32) cout << "YES";
	 	else if (m == n/32) {
	 		if (n % 32 == 0) cout << "YES";
	 		else cout << "NO";
	 	}
	 	else cout << "NO";
		cout << endl;
    }
 	
    return 0;
}