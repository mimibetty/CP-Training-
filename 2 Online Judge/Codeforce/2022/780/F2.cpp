
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
#define For(i, S, r) for (int i = l; i < r; i++)
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
 
int a[500005];
int ps[500005];
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') a[i+1] = 1;
        else a[i+1] = -1;
        ps[i+1] = ps[i] + a[i+1];
    }

    ll cnt = 0;
    multiset<int>s0,s1,s2;

    for (int i = 1; i <= n; i++) {
        int pl = ps[i]%3;
        
        if (pl == 0) {
            auto d = s0.upper_bound(ps[i]);
            d--;
            if (d == s0.begin()) {
                continue;
            } 
            
            cnt += *d;
            s0.insert(ps[i-1]);
        }
        if (pl == 1) {
            auto d = s1.upper_bound(ps[i]);
            d--;
            if (d == s1.begin()) {
                continue;
            } 
            
            cnt += *d;

            s1.insert(ps[i-1]);
        }
        if (pl == 2) {
            auto d = s2.upper_bound(ps[i]);
            d--;
            if (d == s2.begin()) {
                continue;
            }   
            
            cnt += *d;

            s2.insert(ps[i-1]);
        }
    }

    cout << cnt << endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	
    multiset<int>s;
    for (int i = 1; i <= 5; i++) {
        s.insert(i);
    }

    auto it = s.upper_bound(3);
    cout << *it << endl;
    // cout << it << endl;
 	// int t;
 	// cin >> t;

 	// while(t--) {
 	// 	solve();
 	// }
    return 0;
}