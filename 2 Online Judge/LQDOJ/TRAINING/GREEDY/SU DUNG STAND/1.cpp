#include<bits/stdc++.h>
using namespace std;

struct Stand {
	int dame;
	int mana;
};

bool cmp(Stand a, Stand b) {
	if (a.mana == b.mana) return a.dame > b.dame;
	return a.mana < b.mana; 
};

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	long long res = 0;
 	int maxval = 0;
 	int n,m;
 	cin >> n >> m;

 	vector<int>enemy;
 	vector<Stand>stand;
 	for (int i = 1; i <= n; i++) {
 		int k;
 		cin >> k;
 		enemy.push_back(k);
 	}
 	for (int i = 1; i <= m; i++) {
 		int l,r;
 		cin >> l >> r;
 		stand.push_back({l,r});
 		maxval = max(maxval, l);
 	}   

 	sort(enemy.begin(), enemy.end());
 	sort(stand.begin(), stand.end(),cmp);

 	if (maxval < enemy[n-1]) cout << "bin9638 da mat Nezuko";
 	else {
 		int vt1 = 0, vt2 = 0;
 		while (vt1 >= 0 && vt1 < n) {
 			if (stand[vt2].dame >= enemy[vt1]) {
 				res += stand[vt2].mana;
 				vt1++;
 			}
 			else vt2++;
 		}		
 		cout << res;
 	}
 	//for (auto i : stand) cout << i.dame << ' ' << i.mana << endl;
    return 0;

}