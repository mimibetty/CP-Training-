#include<bits/stdc++.h>
using namespace std;

//int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int a,b,c,d;
    int res = 0;
    cin >> a >> b >> c >> d;
    for (int i = 0; i <= d/a; i++) {
    	for (int j = 0; j <= d/b; j++) {
    		for (int r = 0; r <= d/c; r++) {
    			if (a * i + b * j + r * c == d) res = max ( res , i + j + r);
    			if (a * i + b * j + r * c > d) break; 
    		}
    	}
    }
    cout << res;
    return 0;
}