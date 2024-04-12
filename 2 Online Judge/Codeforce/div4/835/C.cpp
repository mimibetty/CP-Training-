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

int l[200005];
int r[200005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        r[i] = 0;
        l[i] = 0;
    }
    for (int i = 1;  i<= n; i++) {
        cin >> a[i];
    }
    l[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] <= a[i-1]) l[i] = 1;
        else {
            // l[i] = 1;
            break;  
        } 
    }

    for (int i = n; i >= 1; i--) {
        if (a[i] >= a[i-1]) r[i] = 1;
        else {
            // cout <<"FFF" << endl;
            r[i] = 1;
            break;  
        } 
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << l[i] << ' ';
    // }
    // cout << endl;

    // for (int i = 1; i <= n; i++) {
    //     cout << r[i] << ' ';
    // }
    // cout << endl;

    for (int i = 1; i <= n; i++) {
        if (l[i] == 1 && r[i] == 1) {
            cout << "YES" << endl;
            return;
        }
    }
    if (r[1] == 1) {
        cout << "YES" << endl;
        return;

    } 
    cout << "NO" << endl;
       
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
    // t = 1;
    while (t--) solve();
    return 0;
}