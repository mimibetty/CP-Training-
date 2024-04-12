#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int uoc[6000005];
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int m=5000005;
    for (int i = 1; i <= m; i++) {
         for (int j = i; j <= m ; j+=i) {
           uoc[j]+=i;
         }
    }
    int n;
    long long res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	if (a[i] * 2 > uoc[a[i]] ) {
    		res++;
    		//cout << a[i] << ' ';	
    	}
    }    
    cout << res;
    return 0;
}