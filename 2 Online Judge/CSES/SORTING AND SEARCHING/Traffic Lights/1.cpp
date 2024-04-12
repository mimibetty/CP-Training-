#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
	int n,m;
 	cin >> n >> m;
 	set<int>trafic;
 	multiset<int>res;
 	trafic.insert(0);
 	trafic.insert(n);

 	res.insert(n);
 	
 	for (int i = 1; i <= m; i++) {
 		int k;
 		cin >> k;

 		auto j = trafic.upper_bound(k);
 		auto valR = *j;
 		j--;
 		auto valL = *j;
 		trafic.insert(k);

 		res.erase(res.find(valR - valL) );
 		res.insert(abs(valR - k));
 		res.insert(abs(valL - k));
 		int maxVal = *(--res.end()); // số lớn nhất
 		cout << maxVal << ' ';
 	}
    return 0;
}