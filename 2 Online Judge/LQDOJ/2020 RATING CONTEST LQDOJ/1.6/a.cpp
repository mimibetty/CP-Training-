#include<bits/stdc++.h>
using namespace std;
long long a[10000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
    	long long maxvl = 0, minvl = 1e9;
       	long long n, x;
    	cin >> n >> x;
    	long long sum = 0;
    	for (int i = 1; i <= n; i++) {
    		cin >> a[i];
    		maxvl = max(a[i],maxvl);
    		minvl = min(a[i],minvl);
    		sum += a[i];
    	}
    	sum += x;
    	if (x < maxvl) {   	
    	   cout << "NO";	
    	}
    	else if (x == maxvl) {
    		if (minvl == maxvl) cout << "YES";
    		else cout << "NO";
    	}
    	else {
    		if (sum  % (n+1) == 0) cout << "YES";
    		else cout << "NO";
    	}
    	cout << endl; 
    }
    return 0;
}
