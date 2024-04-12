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


ll a[1005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while(t--) {
        ll n,h;
        cin >> n >> h;
        for (int i =1; i<= n; i++) {
            cin >> a[i];
        }
        sort(a+1,a+1+n);
        ll res = 1e9;
        if (n == 1) {
            cout << h/a[1] << endl;
        }
        else {
            ll cnt = h/(a[n] + a[n-1]);
            if (cnt * (a[n] + a[n-1]) != h) cnt++;
            if (cnt*a[n] + cnt*a[n-1] - h >= 0) res = min(res, cnt*2);
            if (cnt*a[n] + (cnt-1)*a[n-1] - h >= 0) res = min(res, cnt*2 -1);
            if ((cnt-1)*a[n] + (cnt-1)*a[n-1] - h >= 0) res = min(res, cnt*2 -2);
            // cout << cnt << endl;
            cout << res << endl;   
        }
    }

    return 0;
}