#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    map<int,int >d;
    set<int>s;
    int n;
    long long k, res = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	d[a[i]++];
    	s.insert(a[i]);
    }
    for (auto i: s) {
    	//int q = k - s[i];
    	cout << s;
    	cout << endl;
    }
    return 0;
}