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

pair<long long, long long>b[200005];
void solve() {
    long long n,m;
    cin >> n >> m;
    vector<long long>a;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i].se >> b[i].fi;
    }
    sort(b + 1, b + 1 + m);
    reverse(b + 1, b + 1 + m);

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= b[i].se; j++) {
            if (cnt == n) break;
            cnt++;
            a.push_back(b[i].fi);
        }
        if (cnt == n) break;
    }
    sort(All(a));
    reverse(All(a));
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    }
    cout << res << endl;;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    
    solve();
    return 0;
}