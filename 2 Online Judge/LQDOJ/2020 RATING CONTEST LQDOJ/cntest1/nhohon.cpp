#include<bits/stdc++.h>
using namespace std;

long long a[1000005];

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    map<long long , long long >d,k;
    set<long long>s;
    int n;
    long long minval = 1e9;   
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	d[a[i]]++;
    	s.insert(a[i]);
    	minval = min(minval,a[i]);
    }
    k[minval] = 1;
    long long old = 0;
    for (auto i: s) {

    	k[i] = k[old] + d[old];
    	old = i;
    	//k[d[i]] += d[i-1];
    }
    for (int i = 1; i <= n; i++) cout << k[a[i]] << ' ';
   
    return 0;
}