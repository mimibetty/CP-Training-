#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int t;
 	cin >> t;
 	for (int q = 1; q <= t; q++) {
 		string s;
 		cin >> s;
 		int l = s.size();
 		for (int i = 0; i < s.size(); i+=2) {
 			cout << s[i];
 		} 
 		cout << s[l-1];
 		cout << '\n';

 	}   
    return 0;
}