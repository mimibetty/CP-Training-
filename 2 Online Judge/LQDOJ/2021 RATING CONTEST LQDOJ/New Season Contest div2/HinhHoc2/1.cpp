#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

 	int t;
 	cin >> t;
 	
 	for (int f = 1; f <= t; f++) {
 		long long x,y,q,p;
 		cin >> x >> y >> p >> q;
 		x *= 1.0;
 		y *= 1.0;
 		p *= 1.0;
 		q *= 1.0;

 		double a = 0,res = 0;
 		a = q * y /(p * x);
 		a = pow (a, 1.0/3);
		res = p * x * sqrt( a * a + 1.0 ) + q * y * sqrt(1.0 + 1.0/(a*a) );
		cout << fixed << setprecision(9) << res;
		cout << endl;
 	}    
    return 0;
}