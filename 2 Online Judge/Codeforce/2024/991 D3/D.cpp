/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
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
int a[200005];
void solve() {
    string b;
    cin >> b;
    int n = b.size();

    int i = 0;
    for (char c : b) {
        i++;
        a[i] = c - '0';
    }

    set<pair<int,int>>s;
    for (int i = 1; i <= n; i++) {
        // cout << a[i] << ' ';
        s.insert({i,a[i]});
    }
    // cout << endl;

    // for (auto i : s) cout << i.fi << ' ' << i.se << endl;
    // cout << endl; 

    vector<int>res;
    int vt = 0;
    while (s.size() > 0) {
        // vt++;
        // cout <<"VT  " << vt << endl;
        int pos = 0;
        pair<int,int>pick = {0,0};
        int maxVal = -1e9;
        for (auto i : s) {
            // cout << i.fi << ' ' <<i.se << endl;
            pos++;
            if (maxVal < i.se - pos + 1) {
                maxVal = i.se - pos + 1;
                pick = i;
            }
            if (pos == 9) break;
        }
        // cout << endl;
        s.erase(pick);
        res.pb(maxVal);
    }

    for (auto i : res) cout << i;
    cout << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll x = pow(2,20) * 20;
    cout << x << endl;
    return 0;

    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}