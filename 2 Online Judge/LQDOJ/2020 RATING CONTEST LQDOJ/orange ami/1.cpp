#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int l, n , cnt = 0;
 	cin >> l;
 	string s;
 	cin >> s;
 	cin >> n;
 	for (int i = 0; i < l;i++) if (s[i] == '1') cnt++;
 	for (int q = 1; q <= n; q++) {
 		int k;
 		cin >> k;
 		if (cnt >= k) cout << "Ami Dep Trai";
 		else cout << "Luong Xiao Lin";
 		cout << '\n';
 	}
    return 0;
}