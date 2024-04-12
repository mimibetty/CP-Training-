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

int cnt[15];

void solve() {
    int n;
    cin >> n;
    int a;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cnt[a%10]++;
    }
    vector<int>x;
    for (int i = 0 ; i <= 9; i++) {
        for (int j = 1; j <= min(3,cnt[i]); j++) {
            x.pb(i);
        }
    }
    // for (auto i : x) cout << i << ' ';

    int num = x.size();
    num--;
    bool ok = 0;
    for (int i = 0; i <= num - 2; i++) {
        for (int j = i + 1; j <= num - 1; j++) {
            for (int k = j + 1; k <= num; k++) {
                if ((x[i] + x[j] + x[k]) % 10 == 3) {
                    ok = 1;
                    break;
                }
            }
        }
    }

    if (ok) {
        cout << "YES " << endl;

    }
    else cout << "NO" << endl;
    for (int i = 0; i <= 9; i++) cnt[i] = 0;
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