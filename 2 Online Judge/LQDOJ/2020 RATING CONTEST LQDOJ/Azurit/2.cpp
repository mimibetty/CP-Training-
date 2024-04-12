#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int t ;
 	cin >> t;
 	map<int, int>d;
 	set<int>s;
 	for (int q = 1; q <= t; q++) {
 		int x,k,res; 
 		cin >> k >> x;
 		if (q == 1) res =x; 
 		if (k == 1) {
 			s.insert(x);
 			d[x]++;
 			if (d[x] == 1) {
 				res = *s.begin();
 				for (auto i : s) res = __gcd(res,i);	
 			}
 		}
 		else {
 			d[x]--;
 			if (d[x] == 0) {
 				s.erase(x);
				res = *s.begin();
 				for (auto i : s) res = __gcd(res,i);
 			}	
 		}
 		cout << res << '\n';
 	}   
    return 0;
}