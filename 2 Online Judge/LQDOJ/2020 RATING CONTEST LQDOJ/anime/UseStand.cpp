#include<bits/stdc++.h>
using namespace std;

int a[1000005];
bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
	if (a.first > b.first) return 1;
	else if (a.first == b.first) return (a.second > b.second);
	return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n,m;
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 	}   
 	sort(a + 1, a + 1 + n);

 	int maxvl = 0, res = 0;
 	vector<pair<int,int>> stand;
 	for (int i = 1; i <= m; i++) {
 		int b,c;
 		cin >> b >> c;
 		stand.push_back({b,c});
 		maxvl = max(maxvl, b);
 	}
 	sort(stand.begin(), stand.end(),cmp);
 	reverse(stand.begin(), stand.end() );
 	for (auto i: stand) cout << i.first << ' ' << i.second << endl;
 	if (maxvl < a[n] ) cout << "bin9638 da mat Nezuko";
 	else {
 		
 	}
 3 5 4 7 2
    return 0;
}