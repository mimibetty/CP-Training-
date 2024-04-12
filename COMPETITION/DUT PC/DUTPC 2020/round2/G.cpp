#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int o = 1; o<= t; o++) {
    	int k,sl = 0;
    	bool done = 1;
    	cin >> k;
    	string a,b,s;
    	cin >> s >> a >> b;
    	int ns = s.size();
    	int na = a.size();
    	int nb = b.size();
    	sl = k + na + nb;
   // 	cout << na << ' ' << nb << ' ' << ns << ' ' << sl;
    	if (ns > sl) done = 0;
    	for (int i = 0; i < na; i++) {
    		if(s[i] != a[i]) {
    			done = 0;
    			break;
    		}	
    	}
    	for (int i = 0; i < nb; i++) {
    	//	cout <<s[ns-nb+i];
    		if(s[ns-nb+i] != b[i]) {	
    			done = 0;
    			break;
    		}
    	}	

    	if ( done == 1) cout << "YES";
    	else cout << "NO";
    	cout << '\n';
	}   
    return 0;
}