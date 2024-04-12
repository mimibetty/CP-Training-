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

int a[1000];
void solve() {
    int n;
    cin >> n;
    int l = 2, r = n; 
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1) {
            cout << r << ' ';
            // a[i] = r;
            r--;
        }
        else {
            cout << l << ' ';
            // a[i] = l;
            l++;
        }
        // cout << i << endl;
    }
    cout << 1 << endl;
    // a[n] = 1;
    // for (int i = 1; i <= n; i++) cout << a[i] << ' '; 
    // EL; 

    // for (int i = 1; i < n; i++) {
    //     for (int j = 1; j < n; j++) {
    //         if (a[i] % a[j] == 0 && a[i + 1] % a[j + 1] == 0 && i != j && i + 1 <= n && j + 1 <= n) {
    //             cout << "NO  " << n << " " << a[i] << ' ' << a[j] << endl;
    //             return;
    //         }
    //     }
    // }
    // cout << "OK   " << n << endl;
    // cout << endl;
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

    // int t;
    // for (int i = 1;  i <= 50; i++) {
    // solve(i);

    // } 
    
    return 0;
}