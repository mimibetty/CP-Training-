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

pii a[200005];
void solve() {
    
    int n,k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n);
    multiset<int>s;
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].fi << ' ' << a[i].se << endl; 
    // }
    // EL;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        while (s.size() > 0) {
            auto end = *s.begin();
            if (end <= a[i].fi) {
                s.erase(s.find(end));
            }
            else break;
        }
        if (s.size() < k) {
            s.insert(a[i].se);
            res++;
        }
        else {
            auto end = *s.rbegin();
            if (a[i].fi >= end) {
                s.erase(s.find(end));
                s.insert(a[i].se);
                res++;
            }
            else {
                if (a[i].se < end) {
                    s.erase(s.find(end));
                    s.insert(a[i].se);   
                }
            }
        }
        // cout << i << ' ' << res <<endl;
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
    
    solve();
    
    return 0;
}