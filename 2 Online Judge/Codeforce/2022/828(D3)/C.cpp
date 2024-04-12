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

int bin(int x, vector<int>&a) {
    int l = 0, r = a.size() - 1;
    int mid ;
    // cout << l << ' ' << r <<endl;
    while(l < r) {
        mid = (l + r)/2;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
        // cout << l << ' ' << r << ' ' << mid <<' ' << a[mid] << endl;
    }

    if (a[l] > x) return a[l] - x;
    return -1;
}

void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    s = ' ' + s;

    vector<int>a[4];
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'r') {
            a[0].pb(i);
        }
        if (s[i] == 'g') {
            a[1].pb(i);
        }
        if (s[i] == 'y') {
            a[2].pb(i);
        }
    }
    // if (c == 'g' && a[1].size() == 1) {
    //     cout << 0 <<endl;
    //     return;
    // }
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'r') {
            a[0].pb(i+n);
        }
        if (s[i] == 'g') {
            a[1].pb(i+n);
        }
        if (s[i] == 'y') {
            a[2].pb(i+n);
        }
    }
    // for (auto i : a[0]) cout << i << endl;
    // cout << bin(1,a[0]) << endl;
    int res = 0;
    
    if (c == 'r') {
       for (auto i : a[0]) {
            if (i > n) break;
            res = max(res, bin(i,a[1]));
        } 
    }
    else if (c == 'g') {
       for (auto i : a[1]) {
            if (i > n) break;
            res = max(res, bin(i,a[1]));
        } 
    }
    else {
        for (auto i : a[2]) {
            if (i > n) break;
            res = max(res, bin(i,a[1]));
        } 
    }
        cout <<res <<endl;

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