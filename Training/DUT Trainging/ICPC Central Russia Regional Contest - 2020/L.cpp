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

string s;
void flipp(int l, int r) {
    int mid = (l + r)/2;
    int cnt = 0;
    for (int i = l ; i <= mid; i++) {
        swap(s[i], s[r-cnt]);
        cnt++;
    }

}
void solve() {
    cin >> s;
    s = ' ' + s;
    vector<pii>a;
    a.pb({1,s.size() - 1});
    int n = s.size() - 1;
    ll x = 1;
    ll mu = 0;
    while (x < (n-1)) {
        x *= 2;
        mu++;
    }   
    flipp(1,n);
    for (int z = 1; z < mu; z++) {
        vector<pii>seg;
        for (auto [x,y] : a) {
            seg.pb({x, (x+y)/2});
            seg.pb({(x+y)/2 + 1, y});
        }
    
        a = seg; 
        for (int c = 0; c < a.size(); c++) {
            int l = a[c].fi;
            int r = a[c].se;
            flipp(l,r);
        }
        // cout <<"SSS " << endl;
        // for (auto [x,y] : a) {
        //     cout << x << ' ' << y << endl;
        // }    
        // cout << s << endl;
    }
    for (int i = 1; i <= n; i++) cout << s[i];
    // cout << s << endl;
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