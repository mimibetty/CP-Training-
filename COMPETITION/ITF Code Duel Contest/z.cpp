/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

int trace[1000005];
// faster
const long long MOD = 1e9 + 7;
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
map<int,int>d; 

int cnt[100005];

vector<pair<long long, long long>>f;
ll res = 0;

bool snt(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}
void doit(int pos) {
    if (pos == f.size()) {
        res++;
        if (res >= MOD) res -= MOD;
    }

    for (auto [keys,vals] : d) {
        if (vals + 1 >= f[pos].se) {
            d.erase(keys);
            doit(pos + 1);
            d[keys] = vals;
        }
    }
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
  
    long long n,k;
    cin >> n >> k;
    if (k >= n && snt(k) == 1) {
        cout << 0 << endl;
        return 0;
    }
    sieve(100000);
    // for (int i = 1; i <= n; i++) {
    //     if (trace[i] == i) {
    //         d[i] = 1;
    //         // cout << i << ' ';
    //     }
    // }
    // EL;
    int tmp = k;
    for (int i = 2; i <= sqrt(tmp); i++) {
        if (tmp % i == 0) {
            int cnt = 0;
            while (tmp % i == 0) {
                cnt++;
                tmp /= i;
            }
            f.push_back({i, cnt});
        }
    }
    if (tmp > 1) {
        f.push_back({tmp,1});
    }


    for (int i = 1; i <= n; i++) {
        int tmp = i;
        while (tmp > 1) {
            d[trace[i]]++;
            tmp /= trace[i];
        }
    }
    doit(0);
    cout << res <<endl;
    // vector<pair 
    // for (int i = 1; i <= n; i++) {
    //     if (cnt[i] > 0) cout << i << ' ' << cnt[i] << endl;
    // }
    // for (auto i : f) cout << i.fi << ' ' << i.se << endl;
    return 0;
}