#include<bits/stdc++.h>
using namespace std;

long long a[1000005];
long long d[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	long long n;
 	cin >> n;

 	bool done = 0;
 	

 	for (int i = 1; i <= n; i++ ) {
 		cin >> a[i];
 		d[a[i]]++;
 		if (d[a[1]] > 1 || d[a[n]] > 1) done = 1; 
 	}

 	if (done == 1) {
 		cout << n - 1;
 	}   
 	else cout << -1;
    return 0;
}