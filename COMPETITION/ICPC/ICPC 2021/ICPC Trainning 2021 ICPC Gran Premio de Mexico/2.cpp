#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

void solve() {
    string s;
    string dd;
    cin >> s;
    int n = s.size();
    long long temp = 0;
    for (int i = n-1; i >= n-3 && i>= 0; i--) {
        dd += s[i];
        // temp = temp * 10;
        // temp += s[i] - '0';
    }

    for (int i = dd.size() - 1; i >= 0; i--) {
        temp = temp * 10;
        temp += dd[i] - '0';
    }
    // cout << temp <<endl;
    vector<int>res;
    
    if (temp % 2 == 0) res.pb(2);
    
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i] - '0';
    }
    if (sum % 3 == 0) res.pb(3);
    
    for (int i = 4; i <= 5; i++) {
        if (temp % i == 0) res.pb(i);
    }

    if (temp % 2 == 0 && sum % 3 == 0) res.pb(6);

    // cout << s << ' ' << temp << ' ' << sum << endl;
    if (res.size() == 0) cout << -1 << endl;
    else {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
            if (i != res.size() - 1) cout << ' ';
        }
        cout << endl;
    }

    return;
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