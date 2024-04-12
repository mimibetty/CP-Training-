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
bitset<11>bs;
// void solve() {
//     long long x = 1;
//     vector<long long>a;
//     a.pb(1);
//     vector<vector<long long>>f;
//     for (int i = 1; i <= 10; i++) {
//         x *= 3;
//         a.pb(x);
//     }

//     int len = 10;
//     for (int bit = 0; bit < (1 << len); bit++) {
//         bs = bit;
//         vector<long long>z;
//         for (int i = 0; i < len; i++) {
//             if(bs[i] == 1) z.pb(a[i]);
//         }
//         f.pb(z);
//     }
//     for (int i = 0; i < f.size(); i++) {
//         for (int j = i + 1; j < f.size(); j++) {
//             ll s1 = 0, s2 = 0;
//             for (auto i : f[i]) {
//                 s1 += i;
//             }
//             for (auto i : f[j]) {
//                 s2 += i;
//             }
//             if (s1 > s2) {
//                 swap(f[i],f[j]);
//             }
//         }
//     }
//     int n;
//     while(cin >> n) {
//         bitset<6>bbs;
//         bbs = n-1;
//         if (n == 0) break;
//         cout << n - 1 << ' ' << bbs << ' ' << bbs[0] <<  endl;
//         for (auto i : f[n-1]) cout << i << ' ';
//         EL;
//         EL;
//     }
// }

void solve1() {
    unsigned long long x = 1;
    vector<unsigned long long>a;
    unsigned long long limm = 1e18;
    limm *= 10000;
    cout << limm << endl;
    a.pb(1);
    while(x < limm) {
        x *= 3;
        a.pb(x);
    }

    unsigned long long n;
    while(cin >> n) {
        if (n == 0) return;
        cout << n << endl;
        bitset<34>bbs;
        bbs = n-1;
        for (int i = 0; i <= 34; i++) {
            if (bbs[i] == 1) {
                cout << a[i] << ' ';
            }
        }
        cout << bbs;
        EL;
        EL;
    }
}
int main() { 
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    solve1();
    
    return 0;
}