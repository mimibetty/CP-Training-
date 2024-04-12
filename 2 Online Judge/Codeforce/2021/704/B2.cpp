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

pair<int,int>xx[100005];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n ;
        cin >> n;
        vector<int>a;
        a.clear();

        int maxval = 0; 

        for (int i = 1; i <= n; i++) {
            int b;
            cin >> b;
            xx[i-1].fi = max(xx[i-2].fi,b);
            if (xx[i-1].fi == xx[i-2].fi) xx[i-1].se = xx[i-2].se;
            else xx[i-1].se = i-1;
            a.pb(b);
        }

        if (a[0] == n) {
            for (auto i : a) cout << i << ' ';
            cout << endl;
            continue;
        }
        else {
            int csOld = n;
            int csNew = n-1;
            while (csNew >= 0) {

                csNew = xx[csNew].se;
                for (int i = csNew; i < csOld; i++) cout << a[i] << ' ';
                csOld = csNew;
                csNew--;
            }
            cout << endl;
        }
    }    
    return 0;
}