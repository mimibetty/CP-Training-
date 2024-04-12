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

    int even = 0, odd = 0;
    
    int minodd = 1e9, mineven = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            mineven = min(mineven, a[i]);
        }
        else minodd = min(minodd, a[i]); 
     }
     for (int i = 1; i <= n; i++) {
        bool ok_even = 0;
        bool ok_odd = 0;
        if (a[i] % 2 == 0) ok_even = 1;
        else ok_odd = 1;

        if (a[i] - minodd > 0) {
            if ((a[i] - minodd) % 2 == 0) ok_even = 1;
            else ok_odd = 1;
        }
        if (a[i] - mineven > 0) {
            if ((a[i] - mineven) % 2 == 0) ok_even = 1;
            else ok_odd = 1;
        }
        even += ok_even;
        odd += ok_odd;
        
     }
     if (even >= n || odd >= n) {
        cout << "YES" << endl;
     }
     else cout << "NO" <<endl;
     // cout << even << ' ' << odd << endl;
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