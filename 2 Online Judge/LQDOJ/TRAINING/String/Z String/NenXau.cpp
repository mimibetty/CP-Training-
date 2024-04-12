#include<bits/stdc++.h>
using namespace std;

string s[100005];
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
    int k;
    cin >> k;
    for (int i = 1 ; i <= k; i++) cin >> s[i]; 
    string a;
	a = s[1];
	for (int i = 2 ; i <= k; i++) {
		int n = s[i].size(), res = 0;
		string combi;

	// so sanh 2 truong hop
		if (a.size() > s[i].size() ) {
			combi = s[i] + "&";
			for (int j = a.size() - n; j < a.size(); j++)	combi+= a[j];
		}

		else if (a.size() < s[i].size() ) { 
			for (int j =  0; j < n; j++) combi += s[i][j];
			combi += "&";
			combi += a; 
		}

		else {
			combi = s[i] + "&" + a;	
		}
		
		vector<int> z = zAlgo(combi);
		for (int j = n + 1; j < combi.size(); j++ ) {
			if (z[j] + j == combi.size() ) {
				res = z[j];
			//cout << 1 << endl  << a << endl;
				break;	
			}
			//cout << z[i] + i << ' ';
		}
		//cout << res << endl;
		
		for (int j = res; j < s[i].size(); j++ ) a += s[i][j];
		combi.clear();
		z.clear();
	}
	cout << a; 
    return 0;
}