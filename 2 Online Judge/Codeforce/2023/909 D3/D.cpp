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

long long a[200005];
ll p[200];
// ll pw(long long a, ll b) {
//     if (b == 0) return 1;

//     if (b % 2 == 0) return pw(a,b/2) * pw(a,b/2);
//     else  return pw(a,b/2) * pw(a,b/2) * a;

// }
long long combi2(long long n) {
    long long z = n * (n-1) / 2;
    return z;
}
void solve() {
    int n;
    cin >> n;
    map<long long, ll> d;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    long long res = 0;
    res += combi2(d[1]) + combi2(d[2]) + (d[1])*(d[2]);
    for (auto i : d) {
        if (i.fi == 1 || i.fi == 2) continue;
        res += combi2(i.se);
    }
    cout << res <<endl;
    // for (int i =1 ; i <= n;i++) {
    //     for(int j = i+1; j <= n; j++) {
    //         if (pow(p[a[i]], p[a[j]])    ==  pow(p[a[j]], p[a[i]])) {
    //             cout << i << ' ' << j << ' ' << a[i] << ' ' << a[j] << endl;
    //         }
    //     }
    // }
    // EL;
    // EL;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // p[0] = 1;
    // for (int i = 1; i <= 20; i++) p[i] = p[i-1] * 2;
    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}