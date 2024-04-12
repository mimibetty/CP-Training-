#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;


#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
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

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
ll trace[1000005]; // trace[i] là ước NT lớn nhất của i
ll d[1000005];
ll p[1000005];


// faster
void sieve(ll n) {
    for (ll i = 2; i * i <= n; ++i) {
        if (trace[i] == 0) { //if i is prime
            for (ll j = i * i; j <= n; j += i) {
                if (trace[j] == 0) {
                    trace[j] = i;
                }
            }
        }
    }

    for (ll i = 2; i <= n; ++i) {
        if (trace[i] == 0) {
            trace[i] = i;
        }
    }
}

int main() {
 //   freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    
    vector<ll>primes;
    sieve(1e5);

    for (ll i = 2; i <= sqrt(1e9); i++) {
        if (trace[i] == i) primes.push_back(i);
    }
    
    ll t;
    cin >> t;
    while (t--) {
        
    ll res = 0;
    ll L,R;
    cin >> L >> R;
    
    ll stt = 1;    
    for (ll i = L; i <= R; i++) {
        d[stt] = i;
        stt++;
    }
    stt--;

    for (auto i : primes) {
            ll firstnum = (L-1)/i * i + i;
            ll lastnum = R/i * i;
            for (auto j = firstnum; j <= lastnum; j += i) {
                while ( d[j - L + 1] % i == 0) {
                    d[j - L + 1] /= i;
                    p[j - L + 1]++;
                }
            }
    }

    for (ll i = 1; i <= stt; i++) {
        // cout << i + L - 1 << ' ' << d[i] << ' ' << p[i] << endl;
        if ((p[i] == 1 && d[i] == 1) || (p[i] == 0 && d[i] != 1))  {
            res++;
            //  cout <<i+L-1 << ' ' << p[i] << endl;
        }
        p[i] = 0;
        d[i] = 0;
    }
    cout << res << endl;
    }
    return 0;
}