/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
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

const int NN = 5000000;
long long x,y;
int minPrime[NN + 1];
const long long modd = 998244353;
bool d[NN + 1];
// int eulerPhi(int n) { // = n (1-1/p1) ... (1-1/pn)
//     if (n == 0) return 0;
//     int ans = n;
//     for (int x = 2; x*x <= n; ++x) {
//         if (n % x == 0) {
//             ans -= ans / x;
//             while (n % x == 0) n /= x;
//         }
//     }
//     if (n > 1) ans -= ans / n;
//     return ans;
// }
// long long convert(long long )
// void solve() {
//     cin >> x >> y;
//     vector<long long> real;
//     real.pb(0);
//     long long f = 0;
//     for (int i = 1; i <= m; i++) {
//         f += x;
//         real.pb(f);
//     }

//     long long rr = x * y;
//     for (int i = 2; i <= n; i++) {
//         if (minPrime[i] != i) continue;

//         long long l = (x + i-1)/x * x;
//         for (int j = )  
//     }
// }
 
void solve() {
    long long n ,m ;
    cin >> n >> m;
    vector<long long>ans;
    ans.pb(0);
    long long tmp  = n;
    vector<int>ff;
    while (tmp != 1) {
        int z = minPrime[tmp];
        while (tmp % z == 0) {
            tmp /= z;
        }
        d[z]=1;
        ff.pb(z);
    }

    for (int i = 1; i <= m; i++) {
        ll zz = n*i;
        ans.pb(zz);
    }
 
    long long res = 0;
    for (int i = 1; i <= m; i++) {
        // cout << "II   " << i << endl;
        for (auto j : ff) {
            ans[i] -= ans[i]/j;
        }

        int tmp = i;
        while (tmp != 1) {
            int xx = minPrime[tmp];
            while (tmp % xx == 0) {
                tmp /= xx;
            }
            if (d[xx] == 0) {
                ans[i] -= ans[i]/xx;
            }
        }
        res += ans[i];
        if (res >= modd) res %= modd;
    }
    cout << res <<endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 2; i * i <= NN; ++i) {
        if (minPrime[i] == 0) { //if i is prime
            for (int j = i * i; j <= NN; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= NN; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }


    solve();
    return 0;
}