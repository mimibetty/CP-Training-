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
 
long long a[500005];
long long ps[500005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string s;
    cin >> s;

    int t;
    cin >> t;
    while (t--) {
        int n,l,r;
        cin >> n >> l >> r;
        a[l-1] += n;
        a[r] -= n;
    }

    ps[0] = a[0];
    for (int i = 1; i < s.size() ; i++) {
        ps[i] = ps[i-1] + a[i];
        // cout << ps[i] << ' ';
    }

    for (int i = 0; i < s.size(); i++) {
        cout <<char  ('A' + ((ps[i] + int(s[i]) - int('A'))%26));
    //     // cout <<char  (97 + ((ps[i] + int(s[i]) - 97)%26)) << ' ';
    }
    return 0;   
}