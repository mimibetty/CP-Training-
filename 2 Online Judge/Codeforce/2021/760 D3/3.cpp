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
 
ll arr[1005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        for (int i = 1 ; i <= n; i++){
            cin >> arr[i];
        }

        long long gcd1 = arr[1];
        long long gcd2 = arr[2];
        for (int i = 1; i <= n; i+=2) {
            gcd1 = __gcd(gcd1, arr[i]);
        }
        for (int i = 2; i <= n; i+=2) {
            gcd2 = __gcd(gcd2, arr[i]);
        }
        long long res = 0;

        for (int i = 1; i <= n; i+= 2) {
            if (arr[i] %gcd2 == 0) {
                gcd2 = 0;
                break;
            }
        }
        for (int i = 2; i <= n; i+= 2) {
            if (arr[i] %gcd1 == 0) {
                gcd1 = 0;
                break;
            }
        }
        cout << max(gcd1,gcd2) << endl;
    }
 
    return 0;
}