#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n,m;
 	cin >> n >> m;

 	for (int i = 1; i <= n; i++) cin >> a[i];

 	sort(a + 1, a + 1 + n);

 	int res = 1e9;

 	for (int i = 1; i <= n - m + 1 ;i++) {
 		int k = a[i + m - 1] - a[i];
 		res = min(res, k);
 	}
 	cout << res;
    return 0;
}