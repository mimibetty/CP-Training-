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

long long a[100005][4];
int c[35];
int d[35];

void solve() {
    long long n,k;
    cin >> n >> k;
    for (int j = 1; j <= 3; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i][j];
        }
    }
    ll x = k;
    string s;
    while (x) {
        if (x % 2 == 0) s += '0';
        else s += '1';
        x /= 2;
    }
    // reverse(All(s));
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            d[i+1] = 1;
        }
    }
    
    for (int j = 1; j <= 3; j++) {
        bool ok = 0;
        for (int i = 1; i <= n; i++) {
            ll tmp = a[i][j];
            string xx;
            while (tmp) {
                if (tmp % 2 == 0) xx += '0';
                else xx += '1';
                tmp /= 2;
            }    

            for (int i = 0; i < xx.size(); i++) {
                if (d[i + 1] == 0 && xx[i] == '1') {
                    ok = 1;
                    break;
                }
            }
            if (ok == 1) {
                break;
            }

            for (int i = 0; i < xx.size(); i++) {
                if (xx[i] == '1') {
                    c[i+1] = 1;
                }
            }
        }
    }
    int ans = 1;
    for (int i = 1; i <= 32; i++) {
        if (c[i] != d[i]) {
            ans = 0;
            break; 
        }
    }
    if (ans == 1) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    // for (int i = 1; i <= 30; i++) {
    //     cout << d[i] << ' ';
    // }
    for (int i = 1; i <= 34; i++) {
        d[i] = 0;
        c[i] = 0;
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}