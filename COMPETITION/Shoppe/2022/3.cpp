#include <bits/stdc++.h>
using namespace std;

#define precision(x) cout << setprecision(x) << fixed;

int main () {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	double a,b;
	cin >> a >> b;

	double k = 1;
	double n = 1 / a;
	double m = 1 / b;
	precision(6);
	cout << k / (m + n);

    return 0;
}