#include<bits/stdc++.h>
using namespace std;

bool a[500005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int>vt;
    long long res =0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            vt.push_back(i);
        } 
    }

    int sl = vt.size();
    sort(vt.begin(), vt.end()); 

    for (int i = 0; i < sl; i++) {
        res += (n - sl + i + 1 - vt[i]);
    }   
    cout << res ;
    return 0;
}
