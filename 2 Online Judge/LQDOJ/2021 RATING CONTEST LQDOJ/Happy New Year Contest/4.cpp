#include<bits/stdc++.h>
using namespace std;

long long a[5];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for (int p = 1; p <= t; p++) {
    	long long c,u,o,m;
    	long long res = 0;
    	cin >> c >> u >> o >> m;
    	long long cc = c;

    	//sub1 
    	if ( t == 1 && u == o && o == m) {
    		while ( cc % u == 0 && u != 1) {
    			cc /= u;
    			res++;
    		}
    		if (cc == 1) cout << res << endl;
    		else cout << -1 << endl;
    	}

    	//sub3
    	else if ( u == o ) {
    		while (cc % max(m,o) == 0 && max(m,o) != 1) {
    			res++;
    			cc/= max(m,o);
    		}
    		while (cc % min(m,o) == 0 && min(m,o) != 1) {
    			res++;
    			cc/= min(m,o);
    		}
    		if (cc == 1) cout << res << endl;
    		else cout << -1 << endl;
    	}
    	else if ( u == 1 && o == 1 && m == 1) cout << -1 << endl;
    	else {
    		a[1] = u;
    		a[2] = o;
    		a[3] = m;
    		sort (a + 1, a + 1 + 3);

    		for (int i = 3; i >= 1; i--) {
    			while (a[i] != 1 && cc % a[i] == 0) {
	    			//cout << a[i];
	    			res++;
	    			cc = cc/a[i];
	    		}	
    		}
    		if (cc == 1) cout << res << endl;
    		else cout << -1;

    	} 
   	}
    return 0;
}