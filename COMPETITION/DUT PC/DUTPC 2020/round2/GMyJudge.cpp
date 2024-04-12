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
    	int done1 = 1, done2 = 1, done3 = 0;
    	cin >> k;
    	string a,b,s;
    	cin >> s >> a >> b;
    	int ns = s.size();
    	int na = a.size();
    	int nb = b.size();
    	sl = k + na + nb;
   // 	cout << na << ' ' << nb << ' ' << ns << ' ' << sl;
    	if (ns > sl) done1 = 0;
    	for (int i = 0; i < na; i++) {
    		if(s[i] != a[i]) {
    			done2 = 0;
    			break;
    		}	
    	}
        for (int i = ns-1; i >= ns-nb; i--) {
            int vt = 0;
            for (int j = 0; j < nb; j++) {
                if(s[i-nb+1+j] == b[j]) {    
                      cnt     
                }
                else {

                }
           }   
        }
    	
    	if ( done1 + done2 + done3 == 3) cout << "YES";
    	else cout << "NO";
    	cout << '\n';
	}   
    return 0;
}