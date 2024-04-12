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
bool a[200005];
bool b[200005];

void solve() {
    int x = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        x += (1 - a[i]);
    }
    ll temp1 = 0, temp2 = 0,temp3 = 0;
    ll res = 0;


    for (int i = 1; i < n; i++) {
        if (a[i] == 0) x--;
        else temp1 += x;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            a[i] = 1;
            break;
        }
    }

    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    //     cout <<endl;

    x = 0;
    for (int i = 1; i <= n; i++) {
        x += (1-a[i]);
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) x--;
        else temp2 += x;
    }


    for (int i = n; i >= 1; i--) {
        if (b[i] == 1) {
            b[i] = 0;
            break;
        }
    }
     x = 0;
    for (int i = 1; i <= n; i++) {
        x += (1-b[i]);
    }
    for (int i = 1; i < n; i++) {
        if (b[i] == 0) x--;
        else temp3 += x;
    }

    // for (int i = 1; i <= n; i++) cout << b[i] << ' ';
    //     cout <<endl;
    // cout <<temp1 << ' ' << temp2 <<endl;
    res = max({temp1, temp2,temp3});
    cout << res <<endl;
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
    while (t--) solve();
    return 0;
}