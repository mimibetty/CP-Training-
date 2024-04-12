#include<bits/stdc++.h>
using namespace std;

int a[500005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n;
 	cin >> n;
 	long long res =0;

 	for (int i = 1; i <= n ;i++) {
 		cin >> a[i];
 	}

 	sort (a + 1,a + 1 + n);
  	for (int i = 1; i <= n - 2; i++) {
 		for (int j = i + 1; j <= n - 1; j++) {
 			for (int r = j + 1; r <= n; r++) {
 				if (a[i] == a[j] || a[r] == a[j]) {
	 					if (a[i] + a[j] > a[r]) res++;			
 				}
 			}
 		}
 	}
 	cout << res;
    return 0;
}