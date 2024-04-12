#include<bits/stdc++.h>
using namespace std;

int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    long long m,n,k;
    cin >> m >> n >> k;
    long long res = 0;
    set<long long>h;
    set<long long>c;
    for (int q = 1; q <= k; q++) {
    	long long a , b;
    	cin >> a >> b;  
    	h.insert(a);
    	c.insert(b);	
    }
    res = (m - h.size() ) * (n - c.size());
    cout << res;
    return 0;
}