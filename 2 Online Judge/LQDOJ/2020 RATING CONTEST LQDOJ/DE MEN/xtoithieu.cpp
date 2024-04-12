#include<bits/stdc++.h>
using namespace std;

long long a[1000005];
long long bcnn(long long &a, long long &b) {
	long long k = __gcd(a,b);
	return a*b/k;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int t;
 	cin >> t;
 	for (int q = 1; q <= t ; q++) {
 		bool done = 1;
 		long long res = 1; 		
 		int n;
 		cin >> n;
 		for (int i = 1; i <= n; i++) {
 			cin >> a[i];
 		}
 			sort(a+1, a+1+n);
	 		res = a[1] * a[n];
	 		for (int i = 1; i <= n/2; i++) if (a[i] * a[n-i+1] != res ) done = 0;
	 		if (n % 2 != 0 && a[n/2 + 1] * a[n/2 + 1] != res  ) done = 0; 
	 		int l = sqrt(res),cnt = 0;
	 		int vt = 1;
	 		for (int i = 2; i <= l; i++) {
	 			if (res % i == 0) {
	 				cnt +=2;
	 				if (a[vt] != i || a[n-vt+1] != res/i) done =0;
	 				vt++;	
	 			}
	 		}
	 		if (l*l == res ) cnt--;
	 		if (done == 1 && cnt == n) cout << res ;
	 		else cout << -1;
	 		cout <<'\n';	
	 		
    }   
    return 0;
}