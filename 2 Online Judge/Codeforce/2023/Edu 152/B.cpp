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
struct zz {
    int val,vt;
};

bool cmp(zz a, zz b) {
    if (a.val == b.val) {
        return a.vt < b.vt;
    }
    return a.val > b.val;
}
void solve() {
    int n,k;
    cin >> n >> k;
    set<pii>s;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s.insert({x%k,i});
    }
    vector<int>res;
    vector<zz>res2;
    for (auto i : s) {
        if (i.fi != 0) {
            res2.pb({i.fi, i.se});
        }
        else res.pb(i.se);
    }
    
    sort(All(res2), cmp);

    for(auto i :res) cout << i << ' ';
     for (auto i : res2) {
        cout <<  i.vt <<' ';
    }

    EL;
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
    while (t--)   
    solve();
    
    return 0;
}