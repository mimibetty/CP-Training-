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

ll a[200005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll odd = 0,even = 0;
    bool c1 = 0, c2 = 0;
    ll res = a[1];
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            if (a[i] > 0) {
                even += a[i];
                c1 = 1;
            }

        }
        else {
            if (a[i] > 0) {
                odd += a[i];
                c2 = 1;
            }
        }
        res = max(res, a[i]);
    }
    if (c1) res = max(res, even);
    if (c2) res = max(res, odd);
    cout <<res << endl;
    // cout <<res << ' ' << odd << ' ' <<even <<endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while (t--)
    // solve();
    
    int x = 'a';
    cout << x << endl;    
    char z = 97;
    cout << z <<endl;
    return 0;
}