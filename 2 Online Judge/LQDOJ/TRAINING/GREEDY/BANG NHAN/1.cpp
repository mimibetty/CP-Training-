#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	vector<long long>a;
 	int n,m,k;
 	cin >> n >> m >> k;

 	for (int i = 1; i <= n; i++) {
 		for (int j = 1; j <= m; j++) {
 			long long q = i*j;
 			a.push_back(q);
 		}
 	}   
 	sort(a.begin(), a.end());
 	cout << a[k-1];
    return 0;
}