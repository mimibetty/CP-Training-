/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> IndexTree;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> IndexTree;
void solve() {
    int n,k;
    cin >> n >> k;

    IndexTree s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        s.insert({a[i], i});
    }
    auto x = *s.find_by_order((k + 1) / 2 - 1);
    cout << x.fi << ' ';
    // EL;
    // for (auto j : s) cout << j.fi << ' ';
    //     EL;
    int vt = 1;
    for (int i = k + 1; i <= n; i++) {
        s.erase({a[vt], vt});
        s.insert({a[i], i});
        vt++;
        x = *s.find_by_order((k + 1) / 2  - 1);
        cout << x.fi << ' ';
        // EL;
        // for (auto j : s) cout << j.fi << ' ';
        // EL;
    }


}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}