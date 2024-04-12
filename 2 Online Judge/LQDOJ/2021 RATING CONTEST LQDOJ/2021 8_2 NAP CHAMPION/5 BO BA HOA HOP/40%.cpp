#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
    	int n;
    	long long res = 0;
    	cin >> n;
    	for (int i = 1; i <= n; i++) cin >> a[i];
    	for (int i = 1; i <= n - 2; i++) { 
    		for (int j = i + 1; j <= n - 1;j++) {
    			for (int r = j + 1; r <= n; r++) {
    				if ( __gcd(a[i], a[j]) == 1 && __gcd(a[i],a[r]) == 1 && __gcd(a[r],a[j]) == 1) res++;
    				else if ( __gcd(a[i],a[j]) != 1 && __gcd(a[i],a[r]) != 1 && __gcd(a[r],a[j]) != 1) res++;
    				 
    			}
    		}
    	}
    	cout << res << endl;
    }
    return 0;
}