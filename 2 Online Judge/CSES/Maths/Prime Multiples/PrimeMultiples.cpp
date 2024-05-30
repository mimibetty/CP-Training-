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

long long a[25];
bitset<22>bs;
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long n;
    int k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        // cout << a[i] << endl;
    }

    long long res = 0;
    for (int bit = 1; bit < (1 << k); bit++) {
        bs = bit;
        int cnt = cntBit(bit);
        long long lcmm = 1;
        bool ok = 1;

        // cout <<"bitt   " << bit << ' ' << bs << ' ' << cnt << endl;
        for (int j = 0; j < k; j++) {
            if (bs[j]) {
                // cout << a[j + 1] << ' ';
                if (a[j + 1] > (n/lcmm)) { // tran so 
                    ok = 0;
                    break;
                }
                lcmm = lcmm * a[j + 1];  // > n
            }
        }
        // cout << endl;

        if (ok == 0) continue;

        if (cnt % 2 == 1) {
            res += n/lcmm;
        }
        else {
            res -= n/lcmm;
        }
    }
    cout << res << endl;
    return 0;
}