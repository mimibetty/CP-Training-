#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    int k;
    cin >> n >> k;

    multiset<int>s;
  //  vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	s.insert(a[i]);
    }

    int res = 0;

	for (int i = n; i >= 1; i--) {
	//	cout << i << endl;
		auto vt = s.find(a[i]);
		if (vt == s.end()) continue;
		s.erase(s.find(a[i]));
		res++;
		auto m = k - a[i];
		auto x = s.upper_bound(m);
		
		if (x == s.begin()) {
			continue;
		}
		x--;
		if (x == s.end()) continue;
		s.erase(s.find(*x));
	}    
	cout << res;
    return 0;
}