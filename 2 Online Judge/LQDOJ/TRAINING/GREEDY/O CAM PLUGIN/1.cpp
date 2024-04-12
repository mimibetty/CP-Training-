#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	int n,k;
 	cin >> n >> k;

 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 	}   
 	sort (a + 1, a + 1 + n, greater<int>());

 	int vt = 1;

 	while (k > 0 && vt <= n ) {
 		
 	}
    return 0;
}