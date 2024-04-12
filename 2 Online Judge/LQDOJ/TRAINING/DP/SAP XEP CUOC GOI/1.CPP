#include<bits/stdc++.h>
using namespace std;

pair<int, int> a[5005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, int>> a(n+1);

    for (int i = 1; i <= n ;i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

   // for (int i = 1; i <= n; i++) cout << a[i].first << ' ' << a[i].second << endl;
    int res = 0;
    int time = 0;
    
    for (int i = 1; i <= n; i++) {
       // cout << time << ' ' << res << endl;
        if (a[i].first >= time) {
            res++;
            time = a[i].second;
        }
        else time = min(a[i].second, time);
    }
           


    cout << res;
    return 0;
}