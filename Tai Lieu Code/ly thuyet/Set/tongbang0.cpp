#include<bits/stdc++.h>
using namespace std;

long long a[100005];

int main() {
    freopen("input.txt", "r", stdin);
    map <long long, long long>pf,d;
    set < long long, long long> s;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	pf[i] == pf[i-1] + a[i];
    	s.insert(pf[i]);
    }
    s.insert[0]
    return 0;
}