#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;

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

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
const int limx = 1e6;

pair<int,int> a[200005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        set<pii>s;
        vector<pii>res;
        ll cnt =0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            a[i].fi = x;  
            a[i].se = i;
            if (x > 0) s.insert({x,i});        
        }

        while (s.size() > 1) {
            auto max1 = *(--s.end()); // số lớn nhất
            auto max2 = *(--(--s.end()));
            cnt++;
            res.pb({max1.se, max2.se});
            ll val1 = max1.fi - 1, val2 = max2.fi - 1;
            if (val1 > 0) s.insert({val1, max1.se});
            if (val2 > 0) s.insert({val2, max2.se}); 
            s.erase(max1);
            s.erase(max2);
        }
        // cout << "STT" << t << endl;
        cout << cnt << endl;
        for (auto i : res) cout << i.fi << ' ' << i.se << endl;
        s.clear();
        res.clear();
    }

    return 0;
}