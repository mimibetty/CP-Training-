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

int a[100005];
void solve() {
    int n,m,d;
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    int s = m;
    a[m + 1] = n+1;
    
    // cout << n << ' ' << m << ' ' << d <<endl;
    int res = 1e9;
    res += 100;
    int vt = 0;
    if(a[1] == 1) {
        for (int i = 1; i <= m; i++) {
            s += max(0,(a[i+1] - a[i] - 1) / d);
            // cout << i << ' ' << max(0,(a[i+1] - a[i] - 1) / d) <<endl;
        }

        for (int i = 1; i <= m; i++) {
            int x = 0;
            if (i == 1) {
                x = s;
            }
            else {
                x = s - (1 + max(0,(a[i+1] - a[i] - 1) / d)) + max(0,(a[i+1] - a[i-1] - 1)/d);
                x -= max(0,(a[i] - a[i-1] - 1) / d);
            }
            if (x < res) {
                res = x;
            }
        }

        for (int i = 1; i <= m; i++) {
            int x = 0;
            if (i == 1) {
                x = s;
            }
            else {
                x = s - (1 + max(0,(a[i+1] - a[i] - 1) / d)) + max(0,(a[i+1] - a[i-1] - 1)/d);
                x -= max(0,(a[i] - a[i-1] - 1) / d);
            }
            if (x == res) {
                vt++;
            }
        }
    }
    else {
        s++;
        a[0] = 1;
        for (int i = 0; i <= m; i++) {
            s += max(0,(a[i+1] - a[i] - 1) / d);
            // cout << i << ' ' << max(0,(a[i+1] - a[i] - 1) / d) <<endl;
        }
        // cout << s <<endl;
        
        for (int i = 1; i <= m; i++) {
            int x = 0;
            
            x = s - (1 + max(0,(a[i+1] - a[i] - 1) / d)) + max(0,(a[i+1] - a[i-1] - 1)/d);
            x -= max(0,(a[i] - a[i-1] - 1) / d);
            if (x < res) {
                res = x;
            }
            // cout << i << ' ' <<x << ' ' << res << ' ' << vt <<
            // "    " << (1 + max(0,(a[i+1] - a[i] - 1) / d)) <<
            // "    " <<max(0,(a[i+1] - a[i-1] - 1)/d) << endl;
        }
        for (int i = 1; i <= m; i++) {
            int x = 0;
            
            x = s - (1 + max(0,(a[i+1] - a[i] - 1) / d)) + max(0,(a[i+1] - a[i-1] - 1)/d);
            x -= max(0,(a[i] - a[i-1] - 1) / d);
            if (x == res) {
                vt++;
            }
        }           
    }


    cout << res <<' ' << vt <<  endl;
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


