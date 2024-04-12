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

void solve() {
    int n;
    cin >> n;
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        while (a % 2 == 0) {
            a /= 2;
            cnt++;
        }
    }
    if (cnt >= n) {
        cout << 0 << endl;
        return;
    }

    vector<long long>f;
    for (int i = 2; i <= n; i+=2) {
        int z = i;
        int x = 0;
        while (z % 2 == 0) {
            x++;
            z /= 2;
        }
        if(x>0) f.pb(x);
    }
    sort(All(f));
    reverse(All(f));
    int res = 0;
    for (auto i : f) {
        cnt += i;
        res++;
        if (cnt >= n) {
            cout <<res <<endl;
            return;
        }
    }
    cout << -1 << endl;
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