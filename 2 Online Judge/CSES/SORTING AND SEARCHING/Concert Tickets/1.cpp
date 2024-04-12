#include<bits/stdc++.h>
using namespace std;

int a[200005];
int b[200005];

int main() {
  //  freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	multiset<int>s;
 	int n,m;
 	cin >> n >> m;

 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 		s.insert(a[i]);
 	}   
 	for (int i = 1; i <= m; i++) {
 		cin >> b[i];
 	
 	}
 	sort(a+1,a+1+n);

 	for (int i = 1; i <= m; i++) {
 		auto j = s.upper_bound(b[i]);
 		if (j == s.begin()) {
 			cout << -1 <<endl;
 			continue;	
 		}
 		
 		j--;
 		if (j == s.end()) {
 			cout << -1 <<endl;
 			continue;	
 		}
 		cout << *j << endl;	
 		s.erase(s.find(*j));	
 	}
    return 0;
}