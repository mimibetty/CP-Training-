#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n;
 	cin >> n;
 	for (int i = 1; i <= n; i++) cin >> a[i];
 	for (int i = 1; i <= n; i++) {
 		int cnt = 1;
 		int vt = i;
 		int dich = i - 1;
 		dich 
 		if (dich == 0) dich = n;
 		while (kc < n - 1) {
 			while (a[vt] == 0 && a[vt+1] == 0) {
 				vt++;
 				kc++	
 			}
 			if (a[vt] = 0 && a[vt+1] != 0 ) {
 				res++;
 				vt+=a[vt+1];	
 			}
 			whi
 		}

 	}   
    return 0;
}