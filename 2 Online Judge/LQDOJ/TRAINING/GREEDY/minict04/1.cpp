#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int dp[100005];
int trace[100005];

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (trace[i] == 0) {
            for (int j = i; j <= n; j += i) {
                trace[j] = i;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << n / 2 << endl;

    if ( n % 2 == 0) {	
    	for (int i = 1; i <= n/2; i++) cout << 2 << ' ';
    }
    if ( (n-1) % 2 == 0 ) {
    	n -= 3 ;
    	for (int i = 1; i <= n/2; i++) cout << 2 << ' ';
    	cout << 3;
    }
    return 0;
}