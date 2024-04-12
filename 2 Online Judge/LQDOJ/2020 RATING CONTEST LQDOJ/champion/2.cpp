#include<bits/stdc++.h>
using namespace std;

long long a[1000005];
long long pf[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n,k;
 	cin >> n >> k;
 	for (int i = 1; i <= n; i++) {
 	 	cin >> a[i];
 	}  
 	int l, r;
 	l = 1;
 	r = 1;
 	long long res = 0, sum = a[1];
 	while ( r <= n) {
 		if (sum == k) {
 			res++;
 			l = r;
 			sum = 0; 	
 		}
 		if (sum < k) {
 			r++;
 			sum+=a[r];
 		}
 		else	 {
 			sum-=a[l];
 			l++;
 		}
 	}
 	cout << res;
    return 0;
}