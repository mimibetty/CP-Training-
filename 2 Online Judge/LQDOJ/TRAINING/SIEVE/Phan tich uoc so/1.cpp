#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
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

int trace[1000005];

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

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
   
    ll n,x;
    cin >> n;
    x = sqrt(n);
    sieve(x);

    vector<pair<int,int>>primes;
    ll k = n;
    
    for (int i = 2; i <= x; i++) {
        if (trace[i] == i) primes.pb({i,0});
    }
    int last = 0;
    for (int i = 0; i < primes.size(); i++) {
        while(k % primes[i].fi == 0) {
            primes[i].se++;
            k /= primes[i].fi;
            last = primes[i].fi;
        }
    }

    ll cnt = 1;
    for(auto i : primes) {
        if (i.se > 0) {
            cnt *= (i.se + 1);
            for (int j = 1; j <= i.se; j++) {
                if (j == i.se && i.fi == last) cout << i.fi;
                else cout << i.fi << '*';  
            } 
        }
    }

    if (k > 1) {
        cnt *= 2;
        if(last == 0) {
            cout << k;
        }
        else {
            cout << '*' << k;
        }
    }
    cout << endl << cnt;

    return 0;
}