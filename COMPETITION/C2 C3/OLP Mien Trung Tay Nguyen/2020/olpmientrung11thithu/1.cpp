#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    int maxvl = 0, minvl = 10000000;
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	maxvl = max(maxvl, a[i]);
    	minvl = min(minvl, a[i]);
    } 
    

    return 0;
}