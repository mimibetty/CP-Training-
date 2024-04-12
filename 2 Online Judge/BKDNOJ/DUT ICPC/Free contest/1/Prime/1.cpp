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


int trace[10000005]; // trace[i] là ước NT nhỏ nhất của i
// faster
void sieve(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (trace[i] == 0) { //if i is prime
            for (int j = i * i; j <= n; j += i) {
                if (trace[j] == 0) {
                    trace[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (trace[i] == 0) {
            trace[i] = i;
        }
    }
}

ll sum[10000005];
ll num[10000005];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    sieve(1e7);
    for (int i = 1; i <= 1e7; i++) {
        if (trace[i] == i) {
            sum[i] = sum[i-1] + i;
            num[i] = num[i-1] + 1;
        }
        else {
            sum[i] = sum[i-1] ;
            num[i] = num[i-1] ;
        }
    }

    // for (int i = 1; i <= 10; i++) {
    //     // cout << i << ' ' << trace[i] << ' '<< sum[i] << ' ' << num[i] << endl;
    // }
    int t;
    cin >> t;
    while (t--) {
        int l,r;
        cin >> l >> r;
        // long double res = 0;
        // res = (sum[r] - sum[l-1])/(num[r] - num[l-1]);
        precision(2);
        cout << 1.00*(sum[r] - sum[l-1])/(num[r] - num[l-1]);
        cout << endl;
    }
    return 0;
}