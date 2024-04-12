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

int a[200005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int x1 = n, x2 = n;

    int l1 = 1, r1 = n + 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[1]) break;
        else {
            l1 = i;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] != a[1]) break;
        else {
            r1 = i;
        }
    }
    if (r1 == n + 1) {
        x1 = n - l1;
    }
    else {
        x1 = max(0, r1 - l1 - 1);
    }

    

    int l2 = 0, r2 = n + 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[n]) break;
        else {
            l2 = i;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] != a[n]) break;
        else {
            r2 = i;
        }
    }
    if (l2 == 0) {
        x2 = r2;
        x2 = n - (n - r2 + 1);
    }
    else {
        x2 = max(0, r2- l2 - 1);
    }       
    // cout <<x1 << ' ' << l1 << ' ' << r1 << endl << x2 << ' ' << l2 << ' ' << r2 << endl
    // << "RES:  " << min(x1,x2) << endl;
    cout << min (x1,x2 ) << endl;
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