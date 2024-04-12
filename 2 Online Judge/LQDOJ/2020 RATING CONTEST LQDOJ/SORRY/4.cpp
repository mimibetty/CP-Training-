#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,res = 0;
    cin >> n;
    for (int i =1;  i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) res = max(res, abs(i-a[i]));
    	cout << res  << endl ;
    for (int i = 1; i <= n; i++) cout << i << ' ' ;
    return 0;
}