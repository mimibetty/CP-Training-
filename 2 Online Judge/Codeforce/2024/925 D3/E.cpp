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

string a[200005];
void solve() {
    int n;
    ll m;
    cin >> n >> m;
    ll x = 0;
    vector<int>s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        x += a[i].size();
        int f = 0;
        for (int j = a[i].size() - 1; j >= 0; j--) {
            if (a[i][j] != '0') break;
            else {
                f++;
            }
        }
        if (f) {
            s.pb(f);
        }
    }
    sort(All(s));
    // cout << "x " << x << endl;
    // for (auto i : s) cout << i << ' ';
    //     EL;
    bool cc = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (cc) {
            x -= s[i];
        }

        cc = 1 - cc;
    }
    // cout << "x: " << x << ' ' << m << endl;
    if (x > m) {
        cout << "Sasha" <<  endl;
    }
    else cout <<"Anna" << endl;
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