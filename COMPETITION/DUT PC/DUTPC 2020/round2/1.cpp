#include<bits/stdc++.h>
using namespace std;

int e[15];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int o = 1; o<= t; o++) {
    	int a,b, l , k;
	 	int n,m,p,q, r;
	 	cin >> a >> b >> l >> k; 
	 	cin >> n >> m >> p >> q >> r;
		e[1] = n/(2*b);
		e[2] = m/b;
		e[3] = p/b;
		e[4] = q/ l;
		e[5] = r/k;
		sort(e + 1, e + 1 + 5);
		cout << e[1];
		cout << endl;
	}   
    return 0;
}