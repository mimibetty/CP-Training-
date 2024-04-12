#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<long long, long long> pll;
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

int n;
int res[200005];
void solve() {
    cin >> n;

    for (int i = 0; i < 2*n; i++) {
        res[i] = -1;
    }   

    for (int i = n - 1; i >= 0; i--) {
        if (res[i] != -1) continue; 
        int x = sqrt(i);
        if (x*x != i) x++;
        
        bool done = 0;
        while(done == 0) {
            int d = x*x;
            if (d - i < n && d - i >= 0) {
                 if (res[d-i] == -1) {
                    done = 1;
                    res[i] = d-i;
                    res[d-i] = i;
                }
            }
            x++;    
        }
    }


    for (int i = 0; i < n; i++) cout << res[i] <<' ';
        cout << endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}