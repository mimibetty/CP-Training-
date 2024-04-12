#include<bits/stdc++.h>
using namespace std;

int a[1000005], cnt[1000005], x[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
   	cin >> t;
   	for (int q = 1; q <= t; q++) {
   		int n;
   		long long k;
   		cin >> n >> k;
	    for (int i = 1; i <= n; i++) {
	        cin >> a[i];
	        cnt[a[i]]++;
	    } 
	    // x[k] = so luong a[i] chia het cho k
	    for (int i = 1; i <= 1e6; i++) {
	        for (int j = 1; i * j <= 1e6; j++) {
	            x[i] += cnt[i * j];
	        }
	    }
	 	if (x[k] >= 2) cout << "YES";
	 	else  cout << "NO";
	 	cout <<'\n';
 		for (int i = 1; i <= 1e6; i++) {
 			cnt[i] = 0;
 			x[i]= 0;
 		}
   	}
    return 0;
}
