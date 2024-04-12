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

int b[200005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> b[i];
        a[i] = -1;
    }
    // 3 5 7     4 3 8 9 
    // 5 8 7
    if (b[1] > b[2]) {
        a[1] = b[1];
        a[2] = b[2];
    }
    else {
        a[1] = 0;
        a[2] = b[1];
    }

    a[n] = b[n-1];
    // for (int i = 2; i < n; i++) {
    //     if (a[i] != -1) continue;       
    //     if (b[i] > b[i+1]) {
    //         a[i] = b[i];
    //         a[i+1] = b[i+1];
    //     }
    //     else {
    //         a[i] = 0;
    //         a[i+1] = b[i];
    //     }
    // }
    for (int i = 3; i <= n; i++) {
        if (a[i] != -1) continue;       
        if (a[i-1] < b[i-1]) {
            a[i] = b[i-1];
        }
        else {
            a[i] = min(b[i-1],b[i]);
        }
    }
    for (int i = 1; i <=n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    // for (int i = 1; i < n; i++) {
    //     cout << max(a[i], a[i+1]) << ' ';
    // }
    // cout <<endl << endl;

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
    while (t--) solve();
    return 0;
}