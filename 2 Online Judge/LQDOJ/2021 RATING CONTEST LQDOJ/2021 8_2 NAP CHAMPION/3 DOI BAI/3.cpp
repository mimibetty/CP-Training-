#include<bits/stdc++.h>
using namespace std;

int a[2000005];
int vt[200005];
int res[200005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n,m;
 	cin >> n >> m;

 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 		vt[a[i]] = i; 
 	}   
 	for (int i = 1; i <= m; i++) {
 		int l,r;
 		cin >> l >> r;
 		swap(vt[l],vt[r]);		
 	}


 	for (int i = 1; i <= n; i++) {
 		res[vt[i]] = i;
 	}
 	for (int i = 1; i <= n; i++) {
 		cout << res[i] << ' ';
 	}
    return 0;
}