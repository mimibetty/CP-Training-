#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int ps[100005];
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
    	int n, x;
    	int res = 0;
    	bool done = 1;
    	cin >> n >> x;
    	for (int i = 1 ; i <= n; i++)  {
    		cin >> a[i];
    		ps[i] = (ps[i-1] + a[i])% x;
    		if (a[i] % x != 0) done = 0;
    	}
    	if (done == 1) cout << -1;
    	else {
    		for (int i = 1; i <= n; i++) {
    			if (ps[i] % x != 0) res = max(res,i);
    		}
    		for (int i = 1; i <= n; i++) {
    			if ( (ps[n] - ps[i-1]) % x != 0) res = max(res,n-i+1);
    		}
    		cout << res;
    	}
    	cout << endl;
    }
    return 0;
}