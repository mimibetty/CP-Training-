#include<bits/stdc++.h>
using namespace std;

long long a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    map<long long,long long>d,dc;
    set<long long>s,sm;
 	long long n,m;
 	long long res = 0;
 	cin >> n >> m;
 	for (int i = 1; i <= n; i++) {
 		cin >> a[i];
 		d[a[i]]++;
 		s.insert(a[i]);
 		sm.insert(a[i]);
 		sm.insert(a[i]+m-1);
 		sm.insert(a[i]-1);
 	}
 	int gt = 0;;
 	for (auto i:sm ) {
  		dc[i] = d[i] + gt;
 		gt += d[i];
 		//cout << i << ' ' << d[i] << ' ' << dc[i] << endl;
 	}
 	for (auto i:s ) {
 		res = max(res, dc[i+m-1] - dc[i-1] - 1 );
 		//cout << dc[i+m-1] << ' ' << dc[i] << ' ' << res << endl; 
 	}   
 	cout << res;
    return 0;
}
