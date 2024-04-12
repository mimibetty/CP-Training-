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

long long a[100005];
void solve() {
    int n,t;
    cin >> n >> t;
    long long odd = 0, even = 0;
    unsigned long long res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res += a[i];
        if (a[i] % 2 == 0) even++;
        else odd++;
    }

    while (t--) {
        bool x;
        long long y;
        cin >> x >> y;
        if (x == 0) {
            res += y*even;
            if (y % 2 != 0) {
                odd += even;
                even = 0;
            } 
        }
        else {
            res += y*odd;
            if (y % 2 != 0) {
                even += odd;
                odd = 0;
            }
        }
        cout << res <<endl;
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