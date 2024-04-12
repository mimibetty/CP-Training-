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

vector<long long>s;
vector<pii>v;

void backtrack(int vt, vector<pii>&a, long long res) {
    if (vt == a.size()) {
        s.pb(res);
        // cout << res << endl;
        return;
    }

    backtrack(vt + 1, a, res);
    auto x = a[vt];
    for (int i = 1; i <= x.se; i++) {
        res =  res * x.fi;
        // cout << i << ' ' << a[vt] << ' ' << cnt[a[vt]] << ' ' << res << endl;
        backtrack(vt + 1, a, res);
    }
}   

void solve() {
    s.clear();
    v.clear();
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    map<int,int>ff;

    int temp = a;
    for (int i = 2; i <= sqrt(a); i++) {
        int x = 0;
        while (temp % i == 0) {
            temp /= i;
            x++;
        }
        if (x) {
            ff[i] += x; 
        } 

    }
    if (temp > 1) {
       ff[temp]++;
    } 
    

    temp = b;
    for (int i = 2; i <= sqrt(b); i++) {
        int x = 0;
        while (temp % i == 0) {
            temp /= i;
            x++;
        }
        if (x) {
            ff[i] += x; 
        }
    }    
    if (temp > 1) {
        ff[temp]++;
    }

    for (auto i : ff) {
        // cout << i.fi << ' ' << i.se <<endl;
        v.pb({i.fi,i.se});
    }
    // for (auto i : v) cout << i.fi << ' ' << i.se << endl;
    backtrack(0, v, 1);
    sort(All(s));
    // for (auto i : s) cout << i << ' ';
    
    for (auto i : s) {
        long long g = a * b / i;
        long long h = i;
        ll g1 = g, h1 = h;
        if (g <= a) {
            g1 *= (c/g);
        }
        if (h1 <= b) {
            h1 *= (d/h);
        }
        if (g1 > a && g1 <= c && h1 > b && h1 <= d) {
            cout << g1 << ' ' << h1 << endl;
            return;
        }

        // swap(g,h);
        // g1 = g, h1 = h;
        // if (g <= a) {
        //     g1 *= (c/g);
        // }
        // if (h1 <= b) {
        //     h1 *= (d/h);
        // }

        // if (g1 > a && g1 <= c && h1 > b && h1 <= d) {
        //     cout << g1 << ' ' << h1 << endl;
        //     return;
        // }
    }
    cout << -1 << ' ' << -1 <<endl;
    return;
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