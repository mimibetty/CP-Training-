#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    long long k;
    cin >> n >> k;
    long long res = 0;

    for (int i = 1; i <= n; i++) {
    	cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) cout << a[i].first << ' '<< a[i].second << endl; 
    long long i = 1;
    while (k > 0 && i <= n ) {
    	if (k < a[i].first) {
    		cout << res;
    		return 0;
    	}
    	else if ( (k/a[i].first) >=  a[i].second) {
    		k -= (a[i].first * a[i].second);
    		res += a[i].second;
    		i++;
    	}
    	else if (k >= a[i].first ) {
    		res += (k / a[i].first);
    		k = -1;
    	}
    	else break;
    }
    cout << endl << res;
    return 0;
}