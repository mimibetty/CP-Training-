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

bool d[100005];

int trace[10000005]; // trace[i] là ước NT lớn nhất của i
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


// void solve() {
//     int n;
//     cin >> n;
//     vector<int>a;
//     // a.pb(0);
//     for (int i = 2; i <= n; i++) {
//         if (d[i] == 0 && trace[i] == i) {
//             if (d[i*i] == 1 || i*i > n) continue;
//             for (int j = i; j <= n; j *= i) {
//                 if (d[j] == 0) {
//                     a.pb(j);
//                     d[j] = 1;
//                 }
//             }
//         }
//     }
//     for (int i = 2; i <= n; i++) {
//         if (d[i] == 0 && trace[i] == i) {
//             for (int j = i; j <= n; j += i) {
//                 if (d[j] == 0) {
//                     a.pb(j);
//                     d[j] = 1;
//                 }
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++) {
//         if (d[i] == 0) {
//             a.pb(i);
//             d[i] = 1;
//         }
//     }
//     for (auto i : a) cout << i << ' ';
//     EL;
//     for (int i = 1; i <= n; i++) d[i] = 0;
//     // for (int i )
// }
int nxt[100005];
bool ok[100005];
void solve() {
    int n;
    cin >> n; 
    for (int i = 2; i <= n; i++) {
        if (nxt[i] == 0 && i*2 <= n) {
            nxt[i] = i*2;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (ok[i] == 0) {
            int vt = i;
            cout << i << ' ';
            ok[i] = 1;
            vt = nxt[vt];
            while(vt <= n && ok[vt] == 0 && vt > 0) {
                ok[vt] = 1;
                cout << vt << ' ';
                vt = nxt[vt];
            }
        }
    }
    for (int i = 1; i <= n; i++) if (ok[i] == 0) cout << i << ' ';
    EL;
    for (int i = 1; i <= n; i++) {
        ok[i] = 0;
        nxt[i] = 0;
    }   
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    // sieve(100000);

    int t;
    cin >> t;
    while (t--)
    solve();
    
    return 0;
}