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

int a[5];
void solve() {
    for (int i = 1; i <= 4; i++) {
        cin >> a[i];
    }
    int res = 0;
    // if (a[1] > a[3] && a[2] > a[4]) res++;
    // if (a[1] > a[4] && a[2] > a[3]) res++;
    
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            if (j == i) continue;
            for (int z = 3; z <= 4; z++) {
                for (int z2 = 3; z2 <= 4; z2++) {
                    if (z2 == z) continue;
                    if (a[i] > a[z] && a[j] > a[z2]) {
                        // cout << a[i] << ' ' << a[j ]  << ' ' << a[z] << ' ' << a[z2] << endl;
                        res++;  
                    } 
                }
            }
        }
    }
    cout <<res << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    cin >> t;
    while (t--)    
    solve();
    
    return 0;
}