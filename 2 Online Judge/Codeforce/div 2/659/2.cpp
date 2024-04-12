#include<bits/stdc++.h>
using namespace std;
int cnt[200][200];


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int t;
 	cin >> t;
 	for (int q = 1; q <= t; q++) {
 		int n;
 		bool done = 1;
 		int res = 0;
 		cin >> n; 
 		string a,b;
 		cin >> a;
 		cin >> b;
 		for (int i = 0; i < n; i++) {
 			if (a[i] > b[i]) done = 0;
 			else if (a[i] != b[i]) {
 				/*int k = a[i] - '0';
 				int l = b[i] - '0';
*/ 				cnt[a[i]][b[i]]++; 
 			}
 		}
 		if (done == 0) cout << -1 << '\n';
 		else {
 			for (int i = 'a'; i <= 'z'; i++) {
 				for (int j = 'a'; j <= 'z'; j++) {
 					if (cnt[i][j] >= 1) res++; 
 				}
 			}
 			cout << res <<endl;
 		}
 		for (int i = 'a'; i <= 'z'; i++) {
 				for (int j = 'a'; j <= 'z'; j++) {
 					 cnt[i][j] = 0;
 				}
 		}
 	}
    return 0;
}
