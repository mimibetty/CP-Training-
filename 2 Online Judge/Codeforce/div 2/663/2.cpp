#include<bits/stdc++.h>
using namespace std;

char a[105][105];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
	 int t;
 	cin >> t;
 	for (int q = 1; q <=t ; q ++)  {
 		int n,m;
 		cin >> n >> m;
 		for (int i = 1; i <= n; i++) {
 			for (int j = 1; j <= m; j++) cin >> a[i][j];
 		}
 		int res = 0;
 		for (int i = 1; i < n; i++) {
 			if (a[i][m] == 'R') res++;
 		}
 		for (int i = 1; i < m; i++) {
 			if (a[n][i] == 'D') res++;
 		}
 		cout << res << '\n';
 	}     return 0;
}