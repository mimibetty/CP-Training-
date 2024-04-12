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

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    for (ll i = 1; i <= 100; i++) {
        cout << "I:  " << i << endl;
        for (int j = 1; j <= 100; j++) {
            for (int z = 1; z <= 100; z++) {
                ll x = pow(j,z)* z + pow(z,j) * j;
                if (x > i) break;
                if (x == i) {
                    cout << j << ' ' << z << endl;
                    break;
                }
            }
        }
        cout << "Close  " << endl << endl;
    }
    // int t;
    // cin >> t;
    // while (t--) {
    //     ll n;
    //     cin >> n;

    // }
    return 0;
}