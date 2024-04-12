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
int a[200005];

void solve() {
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n ;i++) {
        cin >> a[i];
    }    
    if (a[1] == a[n]) {
        int x = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[1]) x++;
        }   
        if (x >= k) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
        return;
    }
    else {
        int vt = 0;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[1]) {
                cnt++;
                if (cnt == k) {
                    vt = i;
                    break;
                }
            }
        }
        int vt2 = 0;
        int cnt2 = 0;
        for (int i = n; i >= 1; i--) {
            if (a[i] == a[n]) {
                cnt2++;
                if (cnt2 == k) {
                    vt2 = i;
                    break;
                }
            }
        }
        if (vt == 0 || vt2 == 0) {
            cout << "NO" << endl;
            return;
        }
        if (vt < vt2) {
            cout << "YES" << endl;
        }
        else cout << "NO" <<endl;
    }
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
    while (t--)    
    solve();
    
    return 0;
}