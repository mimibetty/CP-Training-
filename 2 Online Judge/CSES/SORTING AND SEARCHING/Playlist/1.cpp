#include<bits/stdc++.h>
using namespace std;

int a[200005];
map <int,int>d;
int main() {
   // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    int res = 0;
    int vt = 0;
    for (int i = 1; i <= n ;i++) {
    	//cout << i << ' ' << d[a[i]] << ' '<< vt << ' ';
    	if (d[a[i]] > 0) {
    		vt = max(vt,d[a[i]]);
    	}
    	res = max(res, abs(i - vt));
    	d[a[i]] = i;
    	//cout << res << endl;
    }
    cout << res;


    return 0;
}