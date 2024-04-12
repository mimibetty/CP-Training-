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
int a[10000];
void solve() {
     int n;
        cin >> n;
        int cnt2 = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 2) cnt2++;
        }

        if (cnt2 == 0) {
            cout << 1 << endl;
            return; 
        }
        if (cnt2 % 2 == 0) {
            for (int i = 1; i <= n; i++) {
                if (a[i] % 2 == 0) cnt++;
                if (cnt == (cnt2/2)) {
                    cout << i << endl;
                    return;
                }
            }
        }
        else cout << -1 << endl;

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