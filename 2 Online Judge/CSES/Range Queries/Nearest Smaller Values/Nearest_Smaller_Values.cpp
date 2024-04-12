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
int res[200005];
void show(stack<pii>s) {
    vector<pii>a;
    while (s.empty() == 0) {
        auto p = s.top();
        s.pop();
        a.pb({p.fi,p.se});
    }
    reverse(All(a));
    for (auto i : a) {
        cout << i.fi << ' '<<i.se << endl;
    }
}
int main() {
    // if(fopen("input.txt", "r")) {
    //     freopen("input.txt","r",stdin);
    //     // freopen("output.txt","w",stdout);
    // }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    stack<pii>s;
    for (int i = 1; i <= n; i++) {
        if (s.empty() == 1) {
            res[i] = 0;
            s.push({a[i], i});
        }
        else {
            auto q = s.top();
            while (q.fi >= a[i]) {
                s.pop();
                if (s.empty() == 1) break;
                q = s.top();
            }

            if (s.empty() == 1) {
                res[i] = 0;
            }
            else {
                res[i] = s.top().se; 
            }
            s.push({a[i],i});

        }
            // cout <<"IIII   " <<i<< endl;
            // show(s);
    }
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    return 0;
}