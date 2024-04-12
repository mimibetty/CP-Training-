#include<bits/stdc++.h>
using namespace std;

pair<long long,long long>a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
 	long long n,k;
 	cin >> n >> k;

 	for (int i = 1; i <= n; i++) {
 		long long  l,r;
 		cin >> l >> r;
 		a[i].first = l; 
 		a[i].second = r;
 	}   

 	sort(a + 1, a + 1 + n);

 	int res = 1;
 	while (k >= a[res].first && res <= n) {
 		k += a[res].second;
 		res++;
 	//cout << k << endl;
 	}
 	cout << res-1;
 	
    return 0;
}