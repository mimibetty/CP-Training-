#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int t;
 	cin >> t;
 	for (int q = 1; q <=t ; q++) {
 		int n;
 		string s;
 		cin >> n;
 		int maxv = 0;
 		for (int i = 1; i <= n; i++) {
 			cin >> a[i];
 			maxv = max(a[i],maxv);
 		}
 		for (int i = 1; i <= maxv+1; i++) s+='a';
 		cout << s << '\n';
 		for (int i = 1; i <= n; i++) {
 				if (s[a[i]] >= 'a' && s[a[i]] < 'z') s[a[i]] = s[a[i]] + 1;
 				else s[a[i]] = s[a[i]] - 1;
 				cout << s;
 				cout << endl;
 			}
 			
 			s.clear();
 	} 
 	
    return 0;
}