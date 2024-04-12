#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int b[1000005];
int vt[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int t;
 	cin >> t;
 	for (int q = 1; q <= t; q++) {
 		int n,res = 1;
 		cin >> n;
 		for (int i = 1; i <= n; i++) {
 			cin >> a[i];
 			b[i] = a[i];
 		}
 		sort(b+1,b+1+n);
 		for (int i = 1; i <= n; i++) {
 			for (int j = 1; j <= n; j++) {
 				if (a[i] == b[j]) {
 					vt[j] = i;
 					break;
 				}
 			}
 		}
 		for (int i = 1; i <= n; i++) {
 			int kq = 1;
 			for (int j = i+1; j <= n; j++) {
 				if (vt[j] > vt[j-1]) {
 					kq++;
 					res = max(res,kq);
 				}
 				else break;
 				//cout << kq << endl;
 			}
 		}
 		//for (int i = 1; i <= n; i++) cout << vt[i] <<' ';
 		for (int i = 1; i <= n; i++) vt[i] = 0;
 		cout << n - res << '\n';
 		
 	}   
    return 0;
}