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
 		long long x, y , n;
 		cin  >> x >> y >> n;
 		long long k = (n/x  * x) + y;
 		if (k > n) cout << k - x;
 		else cout << k;
 		cout <<'\n';
 	}   
    return 0;
}