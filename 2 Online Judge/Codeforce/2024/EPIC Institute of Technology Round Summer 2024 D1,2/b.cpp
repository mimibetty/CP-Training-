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
int premax[200005];

void solve() {
    int n ;
    cin >> n ;
    multiset<int>f;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    premax[1] = a[1];
    for (int i = 2; i <= n; i++) {
        premax[i] = max(premax[i-1], a[i]);
    }
    
    for (int i = 2; i <= n; i++) {
        if (premax[i] - a[i] > 0) {
            f.insert(premax[i] - a[i]);
        }
    }

    long long tmp = 0, res  = 0;
    int pre = 0;
    while(f.size() > 0) {
        // for (auto i : f) cout << i << ' ' ;
        int min_element = *f.begin();
        res += (min_element - tmp) *(f.size() + 1);
        tmp += (min_element - pre);
        pre = min_element;
        // cout << endl << min_element << ' ' << res << ' ' << tmp << endl;
        f.erase(min_element);
    }
    cout << res << endl;

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