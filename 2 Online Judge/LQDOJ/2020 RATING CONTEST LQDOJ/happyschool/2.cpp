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
 		long long n,k;
 		bool done = 1;
 		cin >> n >> k;
 		if (n <= 3 || n*n <= k ) done = 0;
 		if (n % 2 == 0 && k > n ) done = 0;
 		if (n % 2 != 0 && 4*(n-1) > k  ) {
 			done = 0;
 		}
 		if (done == 1) cout << "YES";
 		else cout << "NO";
 		cout << endl;
 	}   
    return 0;
}