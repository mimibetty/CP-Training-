#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;


#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
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

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);

bool xxx[200005];
ll a[200005];
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {

    set<ll> s,x;
    ll maxval = -1e9;
    int n, k;
    cin >> n >> k;
    
    bool xx = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] <= n) xxx[a[i]] = 1;
        else {
            xx = 0;
        }
        s.insert(a[i]);
        maxval = max(a[i],maxval);
    }
    if (xx == 1) {
        for (int i = 0; i < n; i++) {
            if (xxx[i] == 0) {
                xx = 0;
                break;
            } 
        }    
    }
    if (xx == 1) {
        cout << n + k << endl;
        for (int i = 0; i <= maxval; i++) xxx[i] = 0;
        continue;
    }
    for (int i = 0; i <= 3e5; i++) {
        auto it = s.find(i);
        if (it == s.end()) {                    
            x.insert(i);
        }
        if (x.size() == 5) break;
    }      
    ll maxnum = maxval;
    bool check = 1;
    for (int i = 1; i <= k; i++) {
        ll minset = *x.begin(); // số nhỏ nhất
        //cout << i << minset << endl;
        ll d = (maxnum + minset)/2;
        if (d*2 != maxnum + minset) d++;

        auto it = s.find(d);
        if (it == s.end()) {
            maxnum = max(d,maxnum);
            s.insert(d);
            x.erase(d);
        }
        else {
            cout << s.size() << endl;
            check = 0;
            break;
        }

    }
    if (check == 1) cout << s.size() << endl;
    // for (auto i : s) cout << i << ' ';
    s.clear();
    x.clear();
    for (int i = 0; i <= 2e5; i++) xxx[i] = 0;

    }
    return 0;
}