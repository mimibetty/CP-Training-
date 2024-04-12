#include<bits/stdc++.h>
using namespace std;

int a[1000005];
bool check[1000005];
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int t;
 	cin >> t;
 	for (int q = 1; q <= t; q++) {
 		int n;
 		cin >> n;
 		for (int i = 1; i <= n; i++) {
 			cin >> a[i];
 		}
 		int res = n;
 		for (int i = 2; i <= n-1; i++) {
 			if ( (a[i] < a[i-1] && a[i] > a[i+1]) || (a[i] > a[i-1] && a[i] < a[i+1]) ) {
 				res--;
 				check[i] = 1;
 			}
 		}
 		cout << res << '\n';
 		for (int i = 1; i <= n; i++) if (check[i] == 0) cout << a[i] << ' ';
 		cout << '\n';
 		for (int i = 1; i <= n; i++) check[i] = 0;
 	}   
    return 0;
}