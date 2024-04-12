#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n,m;
 	cin >> n >> m;

 	set<int>s;
 	for (int i = 1; i <= n; i++) {
 		int k;
 		cin >> k;
 		s.insert(k);
 		a[k]++;
 	}   
 	for (int i =1; i <= n-m; i++) {
 		int k;
 		cin >> k;
 		a[k]--;
 	} 
 	for (auto i : s) {
 		while (a[i] > 0) {
 			cout << i << ' ';
 			a[i]--;
 		}
 	}
    return 0;
}