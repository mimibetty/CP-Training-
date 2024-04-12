#include<bits/stdc++.h>
using namespace std;

long long a[10005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    long long res = 1,d = 0;
    cin >> n;
    int l,c;
    cin >> l >> c;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
    	if (sum + a[i] == l) {
    		res++;
    		sum = 0;
    	}
    	else if (sum + a[i] < l) sum += a[i];
    	else {
    		int t = l - sum;
    		if (t >= 1 && t <= 10) d-= c;
    		else if (t > 10) d+= (t-10)*(t-10);
    			res++;
    			sum = a[i];	
    	}
    	//cout << d << ' ';
    	//cout << res << ' ' << sum << endl;  
    }
    cout << res << '\n';
    cout << d;
    return 0;
}