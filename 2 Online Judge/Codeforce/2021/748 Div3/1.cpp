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

ll a[5];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        cin >> a[1] >> a[2] >> a[3];
        ll x = max({a[1],a[2],a[3]});
        int cnt = 0;
        for (int i =1; i <= 3; i++) if(a[i] == x) cnt++;

        if (cnt == 1) {
            for (int i =1 ; i<=3; i++) {
                if (x == a[i]) cout << 0 << ' ';
                else cout << abs(x-a[i]) +1 << ' ';
            }
            cout << endl; 
        }
        else {
            for (int i =1 ; i<=3; i++) {
                if (x == a[i]) cout << 1 << ' ';
                else cout << abs(x-a[i]) +1 << ' ';
            }
            cout << endl; 
        }
    }

    return 0;
}