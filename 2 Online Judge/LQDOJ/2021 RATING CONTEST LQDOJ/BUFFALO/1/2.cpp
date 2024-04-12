#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

pair<long long, long long>a[1005];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }    
    int sl = (n-1)*n/2;   
    vector< pair<long long, long long>>dot;    

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n ;j++) {
            long long x = a[j].first - a[i].first;
            long long y = a[j].second - a[i].second;
            dot.push_back({x,y});
        }
    }
    long long res = 0;
    
    for (int i = 0; i < dot.size(); i++) {
        for (int j = i + 1; j < dot.size() ;j++) {
            if ((dot[i].first * dot[j].first) + (dot[i].second * dot[j].second) == 0) {
                res++;
                //cout << i << ' ' << j << endl;
            }
        }
    }
    cout << res;   
    return 0;
}