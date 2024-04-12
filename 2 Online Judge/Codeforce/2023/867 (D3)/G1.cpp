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
    set<ll>s;
    map<ll,ll>cnt;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        s.insert(a[i]);
    }
    ll res = 0;
        
    for (auto i : s) {
        if(cnt[i] >= 3) {
            res += cnt[i]*(cnt[i]-1)*(cnt[i]-2);
        }
    }
    // cout << res <<endl;

    for (auto i  : cnt) {
        ll tmp1 = i.fi;
        ll x = sqrt(tmp1);
        for (int j = 2; j <= x; j++) {

            if (tmp1 % j != 0) continue;
            ll tmp2 = j;
            if (cnt[tmp2] > 0) {
                ll gap = tmp1/tmp2;
                if (tmp2 % gap == 0 && tmp2/gap > 0) {
                    if (cnt[tmp2/gap] > 0) {
                         res += cnt[tmp1]*cnt[tmp2]*cnt[tmp2/gap];
                        // cout << tmp1 << ' ' << tmp2 << ' ' << tmp2/gap <<" "<<cnt[tmp1]*cnt[tmp2]*cnt[tmp2/gap]<< endl;
                    }
                }
            }

            if (tmp2*tmp2 == tmp1) continue;
            tmp2 = tmp1/j;
            if (cnt[tmp2] > 0) {
                ll gap = tmp1/tmp2;
                if (tmp2 % gap == 0 && tmp2/gap > 0) {
                    if (cnt[tmp2/gap] > 0) {
                        res += cnt[tmp1]*cnt[tmp2]*cnt[tmp2/gap];
                        // cout << tmp1 << ' ' << tmp2 << ' ' << tmp2/gap <<" "<<cnt[tmp1]*cnt[tmp2]*cnt[tmp2/gap]<< endl;
                    }
                }
            }
        }
    }
    cout <<res;
    cout << endl;
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