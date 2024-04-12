#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
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
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);

bitset<100005>bs;
vector<int>primes;

void sieve(int n) {
    for (int i = 2; i <= n; i++) bs[i] = 1;

    for (int i = 2; i * i <= n; i++) {
        if (bs[i] == 1) {
            for (int j = i * i; j <= n; j+= i) {
                bs[j] = 0;
            }
        }
    }

    for (int i = 2; i <= n; i++) if (bs[i]) primes.pb(i);
}
void solve() {
    ll l,r,k;
    cin >> l >> r >> k;
    // cout << l << ' ' << r << endl;
    if (l == r) {
        if (l == 1) {
            cout << "NO" << endl;
            return;
        } 
        else {
            cout << "YES" << endl;
            return;
        }
    }

    bool ok = 0;
    for (auto i : primes) {
        ll numA = r/i - (l-1)/i;
        ll numB = r - l + 1 - numA;

        if (numB <= k) {
             ok = 1;
             break;
        }
        // if (numA > 0) {
        //     if (numB <= k) {
        //         ok = 1;
        //         break;
        //     }
        // }
        // else {

        // }
        // if (numB + 1 <= k && numA > 0) {
        //     ok = 1; 
        //     break;
        // }
        // if (numB + 1 <= k && numA == 0) {
        //     ok = 1;
        //     // cout << i << endl;
        //     break;
        // }
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    // cout << endl;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
    sieve(1e3);
 	// cout << primes.size();
    int t;
 	cin >> t;
 	while (t--) {
        solve();
 	}
    return 0;
}