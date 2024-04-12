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

int cnt[1000005];
void solve() {
    int x;
    cin >> x;   
    long long res = 0;
    for (int i = 1; i < x; i++) {
        long long r1 = cnt[i];
        long long r2 = cnt[x-i];
        res += r1*r2;
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
    int lim = 1e6;
    for (int i = 1; i <= lim; i++) {
        for (int j = 1; j <= lim; j++) {
            if (i * j > lim) break;
            cnt[j*i]++;
        }
    }
    solve();
    // for (int i = 1; i <= 30; i++) {
    //     cout << i << ' ' << cnt[i] << ' ';
    //     int z = 0;
    //     for (int j = 1; j <= i; j++) {
    //         if (i % j== 0) z++;
    //     }
    //     cout << z <<endl;
    // }
    
    return 0;
}
