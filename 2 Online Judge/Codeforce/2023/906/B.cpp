/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

void solve() {
    int n,m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    bool ok = 1;
    for (int i = 0; i < n-1; i++) {
        if (s1[i] == s1[i+1]) {
            ok = 0;
        }
    }
    if (ok ) {
        cout << "YES" << endl;
    }
    else {
        ok = 1;
        for (int i = 0; i < m-1; i++) {
            if (s2[i] == s2[i+1]) {
                ok = 0;
            }
        }
        if (ok == 0) {
            cout << "NO" << endl;
            return;
        }
        else {
            ok = 1;
            for (int i = 0; i < n - 1; i++) {
                if (s1[i] == s1[i+1]) {
                    if (s1[i] != s2[0] && s1[i+1] != s2[m-1]) {
                        // ok = 1;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                } 
            }
            if (ok) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}