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

    string s;
    cin >> s;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            sum += i;
        }
        else {
            sum += (n-i-1);
        }
    }
    vector<int>d;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            if (n-i-1 > i) d.pb(n-2*i-1);
        }
        else {
            if (i > n-i-1) {
                d.pb(i - (n-i-1));
            }
        }
    }

    while (d.size() < n) {
        d.pb(0);
    }
    
    sort(All(d));
    reverse(All(d));
    
    for (auto i : d) {
        sum += i;
        cout << sum << ' ';
    }
    cout << endl;
    d.clear();
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