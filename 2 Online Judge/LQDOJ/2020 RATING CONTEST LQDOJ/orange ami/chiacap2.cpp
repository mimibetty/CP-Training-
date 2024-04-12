#include<bits/stdc++.h>
using namespace std;

long long a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	long long n,k;
 	cin >> n >> k;
 	for (int i = 1; i <= n; i++) cin >> a[i];
 	sort(a + 1, a + 1 + n);
 
 	long long res = 0;
 	for (int i = 1; i <= k; i++) {
 		res = max(res,  abs(a[i] - a[n-i]) );
 	}
 	cout << res;
    return 0;
}