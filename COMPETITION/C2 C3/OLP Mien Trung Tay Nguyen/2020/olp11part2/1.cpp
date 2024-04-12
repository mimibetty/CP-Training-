#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int d[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n,res=0;
 	cin >> n;
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 		res = max(res,a[i]);
 		d[i] = d[i-1] + a[i];
 	}   
 	/*for (int i = 1; i <= n; i++) {
 		for (int j = i+1; j <= n; j++) {
 			int q = (a[j] - a[i])/ (j-i+1);
 			res = max(res,q);
 		}
 	}*/
 	cout << res;
    return 0;
}