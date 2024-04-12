#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int t;
 	cin >> t;
 	for (int q = 1; q <= t; q++) {
 		long long n, div3= 0, div2 = 0;
 		cin >> n;
 		long long k = n;
 		while (k % 3 == 0) {
 			div3++;
 			k/=3;
 		}
 		while (k % 2 == 0) {
 			div2++;
 			k/=2;
 		}
 		long long sum = pow(2,div2) * pow(3,div3);
 		//cout << sum;
 		if (n == 1 ) cout << 0;
 		else if (div3 > 0 && div3 >= div2 && sum == n) {
 			cout << max(div3,div2) +  max(div3,div2) - min(div3,div2);
 		}
 		else {
 			cout << -1;
 		}
 		cout <<'\n';
 	}   
    return 0;
}