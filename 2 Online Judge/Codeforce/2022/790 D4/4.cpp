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

ll a[205][205];
        int n,m;
int check(int x,int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m) return 1;
    return 0;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }

        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int xi = i, yi = j;
                long long res = 0;
                
                while (check(xi,yi)) {
                    res += a[xi][yi];
                    xi++;
                    yi++;
                }


                 xi = i, yi = j;
                while (check(xi,yi)) {
                    res += a[xi][yi];
                    xi--;
                    yi--;
                }

                xi = i, yi = j;
                while (check(xi,yi)) {
                    res += a[xi][yi];
                    xi--;
                    yi++;
                }

                xi = i, yi = j;
                while (check(xi,yi)) {
                    res += a[xi][yi];
                    xi++;
                    yi--;
                }

                res -= 3*(a[i][j]);
                sum = max(sum,res);
            }
        }   
        cout << sum << endl;
    }

    return 0;
}