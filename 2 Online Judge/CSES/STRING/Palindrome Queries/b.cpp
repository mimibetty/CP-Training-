#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    // dp_honest[i]: number of ways till position i, ending with honest
    // dp_liar[i]: number of ways till position i, ending with liar
    map<int, int> dp_honest, dp_liar;
    dp_honest[0] = 1; // at position -1, 0 liars, and ending with honest is 1 way.

    for(int i = 0; i < n; ++i) {
        map<int, int> next_honest, next_liar;

        // current position i is honest:
        for(auto &[liars, ways] : dp_honest) {
            if(a[i] == liars) {
                next_honest[liars] = (next_honest[liars] + ways) % MOD;
            }
        }
        for(auto &[liars, ways] : dp_liar) {
            if(a[i] == liars) {
                next_honest[liars] = (next_honest[liars] + ways) % MOD;
            }
        }

        // current position i is liar: previous must be honest
        for(auto &[liars, ways] : dp_honest) {
            next_liar[liars + 1] = (next_liar[liars + 1] + ways) % MOD;
        }

        dp_honest = move(next_honest);
        dp_liar = move(next_liar);
    }

    // sum all ways from honest and liar at last position
    int res = 0;
    for(auto &[_, ways] : dp_honest) res = (res + ways) % MOD;
    for(auto &[_, ways] : dp_liar) res = (res + ways) % MOD;
    cout << res << '\n';
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t; 
    cin >> t;
    while(t--) solve();
}