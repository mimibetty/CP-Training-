#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
 
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
const double PI = acos(-1);
const int limx = 1e6;
 
pair<int,int> a[100005];
pair<int,int> b[100005];
pair<int,int> moon[100005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,m,t;
    cin >> n >> m >> t;
    
    for (int i = 1; i <= n; i++) cin >> a[i].fi;
    for (int i = 1; i <= n; i++) cin >> a[i].se;
    sort(a+1, a+1+n);

    for (int i = 1; i <= m; i++) cin >> b[i].fi;
    for (int i = 1; i <= m; i++) cin >> b[i].se;

    while (t--) {
        int stt;
        cin >> stt;

        for (int i = 1; i <= n; i++) {
            moon[i].fi = b[stt+i-1].fi;
            moon[i].se = b[stt+i-1].se;
        }
        sort(moon + 1, moon + 1 + n);
        int res = 0;
        multiset<int>s;
        int vt = 1;

        for (int i = 1; i <= n; i++) {
            while (vt <= n && a[i].fi > moon[vt].fi ) {
                s.insert(moon[vt].se);
                vt++;
            } 
        
            if (s.empty()) continue;
            if (*s.begin() >= a[i].se) continue;
            auto it = s.lower_bound(a[i].se);

            if (it != s.begin()) it--;

            res++;
            s.erase(it);            
        }

        cout << res << endl;
        s.clear();
    }
    return 0;
}