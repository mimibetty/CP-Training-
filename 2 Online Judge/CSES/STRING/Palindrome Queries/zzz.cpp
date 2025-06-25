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

int a[200005];
struct datar{
    int l, r, val;
    bool operator < (const datar &other) const {
        return val < other.val;
    }
};

long long cal_xor(int l, int r) {
    long long res = a[l];
    for (int i = l; i <= r; i++) {
        res ^= a[i];
    } 
    return res;
}



void solve() {
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<datar> v;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int x = cal_xor(i, j);
            cout << i << ' ' << j << ' ' << x << "  " << endl;
            v.push_back({i, j, x});
        }
    }
    
    // sort(v.begin(), v.end());
    // for (auto i : v) {
    //     cout << i.l << " " << i.r << " " << i.val << "  " << i.r - i.l <<  endl;
    // }
    cout << endl << endl;
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