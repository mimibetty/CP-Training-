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
    int n;
    cin >> n; 
    multiset<int>ar;
    multiset<int>hieu;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ar.insert(a[i]);
    }  
    int pre = -1;
    for (auto i : ar) {
        if (pre != -1) {
            int z = i - pre;
            if (z != 0) {
                hieu.insert(z);
            }
        }
        pre = i;
        // cout <<pre << endl;
    }
    for (auto i : hieu) cout << i << ' ';
        cout << endl;
    int t;
    cin >> t;
    while (t--) {
        int x, ax;
        cin >> x >> ax;
        auto z = ar.lower_bound(a[x]);
        auto y = ar.upper_bound(a[x]);
        cout << *z << ' ' << *y << endl; 
    //     ar.erase(ar.find(a[x]));
    //     a[x] = ax;
    //     ar.inser(ax);
    }
    EL;
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
    while(t--)
    solve();
    
    return 0;
}