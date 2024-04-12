#include<bits/stdc++.h>
using namespace std;

//long long a[2000005];
long long pw(long long a, long long n) {
    if (n == 0) {
        return 1;
    }
    long long q = pw(a, n / 2);
    if (n % 2 == 0) {
        return q*q ;
    }
    else {
        return q*q  * a ;
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    long long n;
    long long cnt = 0,cnt1 = 0;
    //set < long long> s;
    cin >> n ;
    long long res = 0;
	    for (int i = 1; i <= n; i++) {
	    	long long a;
	    	cin >> a;
	    	long long cs = 0;
	    	if (a == 1) cnt1++;
	    	long long k = a;
	    	while ( k % 2 == 0) {
	    		k/=2;
    			cs++;
    		}      		
    		res = max(res, cs); 		
  	 	}
 	if (res > 0)  cout << pw(2,res);
    else cout << 1;
    return 0;
}