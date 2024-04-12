#include<bits/stdc++.h>
using namespace std;

long long a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    long long n;
    cin >> n;
    for (int i = 1; i<= n; i++) cin >> a[i];
  	for (int i = 1; i <= n; i++) {
  		long long res = 0;
  		for (int j = 1; j <= i-1; j++) {
  			if (a[i] > a[j]) res++;
  		}
  		cout << res << ' ';
  	}
    return 0;
}