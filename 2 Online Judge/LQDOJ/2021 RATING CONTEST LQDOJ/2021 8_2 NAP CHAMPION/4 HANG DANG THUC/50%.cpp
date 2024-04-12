#include<bits/stdc++.h>
using namespace std;

int a[100005];
int cnt[100005];
vector<int>d[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n;
 	cin >> n;

 	set<int>s;
 	bool done = 0;

 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 		cnt[a[i]]++;
 		d[a[i]].push_back(i);

 		if (cnt[a[i]] > 1) {
 			done = 1;
 			s.insert(a[i]);
 		}
 	}   

 	if (done == 0) cout << 0;
 	else {
	 	
 		long long res = 0;
 		for (auto i : s) {
 			int leng =d[i].size();
 			for (int l = 0; l < leng - 1; l++) {
 				for (int r = l + 1; r < leng ; r++) {
 					res += (d[i][r] - d[i][l]);
 				}
 			}
 		}
 		cout << res;
 	}
    return 0;
}