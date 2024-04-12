#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	int l = n*(a-b) , r = n*( a + b);
	int ll = c - d, rr = c + d;
	if ( l > rr || r < ll ) cout << "NO";
	else cout << "YES";
	cout << "\n";
}

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1; q <= t ; q++) {
    	solve();
    }
    return 0;
}
