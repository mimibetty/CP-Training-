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

const int limm = 86;
int res = 0;
long long f[90];
void recur(long long n, int step) {
    if (step == limm + 1) {
        if (n == 1) {
            res++;
            return;
        }
    }
    
    if (n == 1) {
        res++;
        return;
    }

    if (f[step] > n) return;
    int cnt = 0;
    long long tmp = n;
    recur(tmp, step + 1);
    while (tmp % f[step] == 0) {
        cnt++;
        // cout << tmp << ' ' <<cnt << endl;
        tmp /= f[step];
        recur(tmp, step + 1);
    } 
    return;
}
void solve() {
    long long n;
    cin >> n;
    recur(n,2);
    cout << res <<endl;
    res =0;

}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    f[0] = 1;
    f[1] = 1;
    map<long long, int >d;
    for (int i = 2 ; i<= 89; i++) {
        f[i] = f[i-1] + f[i-2];
        // cout << i << ' ' << f[i] << endl;
    }

    // for (int i = 2; i <= 89; i++) {
    //     cout << i << ' ' << f[i] << ":   ";
    //     for (int j = 2; j < i; j++) {
    //         if (f[i] % f[j] == 0) cout << f[j] <<' ';
    //     }
    //     EL;
    // }

    // cout << f[86] << endl;
    int t;
    cin >> t;
    while (t--)    {
        solve();
        // EL;EL;
    }
    
    return 0;
}