#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
vector<int> zAlgo(string s) {
    int n = s.length();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i <= n - 1; i++) {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[z[i] + i]) {
            x = i;
            y = i + z[i];
            z[i]++;
        }
    }
    z[0] = n;
    return z;
}


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int q = 1 ; q <= t; q++) {
    	string s,d;
	    cin >> s;
	   	int n = s.size();
	  	d = s;
	  	reverse(d.begin() ,d.end() );
	  	string a = d + "$" + s;
	  	int na = a.size();
	  	vector<int> z;
	  	z = zAlgo(a);
	  	int res = 0;
	  	for (int i = n + 1 ; i < a.size(); i++ ) {
	  		if ( z[i] + i == na) {
	  			res = z[i];
	  			break;	
	  		}
	  		
	  	}
	  	cout << s;
	  	//cout << res;
	  	if (s != d) {
	  		for (int i =  n - res - 1 ; i >= 0  ; i--) cout << s[i];	
	  	}
	  		
	  	cout << endl;
	  	z.clear();	
	  	d.clear();
	  	s.clear();
	  	a.clear();
	}
    
    return 0;
}