#include<bits/stdc++.h>
using namespace std;
 
int a[200005];
 
int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	long long n , k;
 	cin >> n >> k;
 
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 	}
 	sort(a + 1, a + 1 + n);
 
 	long long lower = 1, upper = k * a[n];
        while (lower < upper) {
            long long mid = (lower + upper) / 2;
            long long sum = 0;
            for (int i = 1; i <= n ;i++ ) {
            	sum += (mid / a[i]);
            	if (sum >= k) break;
            }
            if (sum >= k) {
                upper = mid;
            }
            else {
                lower = mid + 1;
            }
        }
    cout << lower;
    return 0;
}