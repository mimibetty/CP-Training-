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

long long f[45];
map<pair<int,int>, bool>d;
void solve() {
    int n;
    cin >> n;
    bool ok = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ok = 1;
        }
    }
    // if (ok == 0) {
    //     return;
    // }
    long long a = 0, b = 1,c;
    d[{0,1}] = 1;
    long long limm = 1e9;
    limm *= 2;
    for (long long i = 2; i <= limm; i++) {
        c = a + b;
        c %= n;
        if (d[{b,c}] == 1) {
            cout  <<n <<' '<< i - 1;
            if (ok == 0) cout << "   ssss";
            cout << endl;
            d.clear();
            break;
            // return;
        }
        d[{b,c}] = 1;
        a = b;
        b = c;
        // cout << a << ' ' << b << ' ' <<c << endl;
    }
    f[1] = 1;
    for (int i = 2; i <= 44; i++) {
        f[i] = f[i-1] + f[i-2];
        f[i] %= n;
        cout << f[i] << endl;
    }
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)    
    solve();
    
    return 0;
}