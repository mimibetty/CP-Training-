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

int n;
int m[25005];
void solve() {
    cin >> n;
    vector<vector<long long>>a;
    a.resize(n+1);
    for (int i = 1; i <= n ;i++) {
        cin >> m[i];
        a[i].resize(m[i]);
        for (int j = 0; j < m[i]; j++) {
            cin >> a[i][j];
        }
        sort(All(a[i]));
    }   
    ll sum = 0;
    ll minn = 1e18;
    int vt = -1;
    ll min2 =1e18;
    for (int i = 1; i <= n ;i++) {
        sum += a[i][1];
        if (minn > a[i][1]) {
            minn = a[i][1];
            vt = i;
        }
        min2 = min(min2, a[i][0]);
    }
    // cout << sum << endl;
    sum = sum - a[vt][1] + min2;
    cout << sum << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (auto j : a[i]) cout << j << ' ';
    //         EL;
    // }
    // EL;
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