#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1; q <=t; q++) {
    	int n, d = 0 ;
    	int c = 0, l = 0;
    	cin >> n;
    	for (int i = 0; i <= n-1; i++) {
    		cin >> a[i];
    		if (a[i] % 2 == 0) c++;
    		else l++;
    		if  (i % 2 == 0 && a[i] % 2 == 0) d++;
    		else if (i % 2 != 0 && a[i] % 2 != 0) d++; 
    	}
    	if (n % 2 == 0) {
    		if ( c == l ) {
    			cout << (n-d)/2;
    		}
    		else cout << -1;
    	}
    	else {
    		if ( c == l+1) {
    			cout << (n-d)/2;
    		}
    		else cout << -1;
    	}
    	cout << '\n';
    }
    return 0;
}