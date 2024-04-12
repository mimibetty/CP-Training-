	#include<bits/stdc++.h>
	using namespace std;

	//int a[1000005];

	int main() {
	    freopen("input.txt", "r", stdin);
	    ios::sync_with_stdio(0);
	    cin.tie(NULL);
	 	long long a,x,q = 1,res = 0;
	 	cin >> a  >> x;
	 	for (int i = 1; i <= x; i++) {
	 		q *= 10;
	 	}
	 	if (a <= q) cout << q-a;
	 	else {
	 		long long k = a;
	 		long long cs = 0;
	 		while (k%10 == 0) {
	 			k/=10;
	 			cs++;
	 		}
	 		if ( cs < x) {
	 			res += (q - a%q);
	 			cout << res ;
	 		}
	 		else cout << 0;
	 		
	 	} 
	    return 0;
	}