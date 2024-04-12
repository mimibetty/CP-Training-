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
  //  freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string a,b,c;
    int res = 0;
    vector<int> d;
    cin >> a >> b;
    c = b + "$" + a;
	d = zAlgo(c);
	for (int i = b.size() + 1; i < c.size(); i++) {
		if (d[i] == b.size()) res++;
	}  
    cout << res;
  
	return 0;
}