	#include<bits/stdc++.h>
	using namespace std;

	long long modMul(long long a, long long b, long long m) {
	    if (b == 0) return 0;
	    long long s = modMul(a, b / 2, m);
	    if (b % 2 == 0) return (s + s) % m;
	    else return (s + s + a) % m;
	}

	long long pw(long long a, long long n, long long m) {
	    if (n == 0) return 1;
	    long long q = pw(a, n / 2, m);
	    if (n % 2 == 0) return modMul(q, q, m);
	    else return modMul(modMul(q, q, m), a, m); 
	}

	int main() {
	    freopen("input.txt", "r", stdin);
	    ios::sync_with_stdio(0);
	    cin.tie(NULL);
		long long x,y,n,m;
		cin >> x >> y >> n >> m ;
		long long res = pw(x,n,m) - pw(y,n,m);
		res = (res%m + m) % m;
		cout << res;    
	    return 0;
	}