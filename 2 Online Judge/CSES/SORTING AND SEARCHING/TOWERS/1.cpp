#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n;
 	cin >> n;

 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 	}   

 	multiset<int>s;

 	for (int i = 1; i <= n; i++) {
 		auto j = s.upper_bound(a[i]);
 		if (j == s.end()) {
 			s.insert(a[i]);
 			continue;	
 		}
 		s.erase(s.find(*j));
 		s.insert(a[i]);
 	}
 	cout << s.size();
    return 0;
}