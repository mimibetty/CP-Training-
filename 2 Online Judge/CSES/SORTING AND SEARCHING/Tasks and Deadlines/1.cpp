#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> a[200005];

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long n;
    cin >> n;

    long long res = 0;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i].first >> a[i].second;
    	res += a[i].second;  
    }

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
    	res -= ((a[i].first) * (n - i + 1)) ;
    }
    cout << res;
 	return 0;
}