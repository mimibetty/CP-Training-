#include<bits/stdc++.h>
using namespace std;

long long a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    long long s;
    bool check0 = 0;
    long long res = 0;
    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	if (a[i] != 0) check0 = 0;
    }

    int q;
    cin >> q;
    for (int m = 1; m <= q; m++) {
    	int x,y;
    	cin >> x >> y;
    }
    if (check0 == 0 && q == 0) {
    	cout <<1;
    	res = (s-n+1)*(s-n+1) + n-1;
    	cout <<res;

    }
    return 0;
}