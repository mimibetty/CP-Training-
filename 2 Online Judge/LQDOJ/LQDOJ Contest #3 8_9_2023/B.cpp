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

long long sp(long long n) {
    long long m = n/2;
    long long maxx = 0;
    for (int i = -10; i <= 10; i++) {
        long long kne w = m + i;
        if (kne w < 0 || kne w > n) continue;
        long long sl = (n - kne w) * kne w;
        maxx = max(maxx, sl);
    }
    return maxx;
}
void solve() {
    long long n;
    cin >> n;
    
    long long l = 0, r = 1e10;
    long long mid;
    while (l < r) {
        mid = (l + r)/2;
        if (sp(mid) >= n) {
            r = mid;
        }
        else l = mid + 1;
        // cout << l << ' ' << r <<endl;
    }
    cout << l << endl;
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
    while(t--)
    solve();
    
    return 0;
}