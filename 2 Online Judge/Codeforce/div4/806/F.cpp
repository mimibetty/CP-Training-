#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<pair<long long,long long>,null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update> IndexTree;
 

long long a[200005];
void solve() {
    int n;
    cin >> n;

    IndexTree values;
    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] >= i) continue;
        if (values.size()) ans += values.order_of_key({a[i], -10000000});

        // ans--;
      
       //  cout << "I  "  <<i << ' ' << a[i] << ' ' << values.order_of_key({a[i], 1000000000}) << "ANS   " << ans << endl;
       // cout << "TEST   \n";
       //  for (auto i : values) {
       //      cout << i.fi << ' ' << i.se << endl;
       //  }
        values.insert({i,a[i]});
        
    }

    cout << ans << endl;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // IndexTree s; 
    // for (int i = 1; i <= 6; i++) {
    //     s.insert({i,i});
    // }
    // for (auto i : s) cout << i.fi << ' ' << i.se << endl;
    // cout <<     s.order_of_key({3,1}); 
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}