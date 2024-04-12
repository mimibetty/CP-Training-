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

int diff(int n) {
    int s = 0;
    while (n) {
        s += n%10;
        n /= 10;
    }
    return s;
}
void solve() {
    vector<pii> ff;
    int n;
    cin >> n;
    int pre = 0;
    for (int t = 1; t <= n; t++) {
        int cnt = 0;
        int z = diff(t);
        for (int i = 0; i <= t; i++) {
            for (int j = 0; j <= t; j++) {
                int k = t - i - j;
                if (k >= 0 && diff(i) + diff(j) + diff(k) == z) {
                    cnt++;
                }
            }
        }
        // cout << cnt << ' ';
        cout <<t << ' ' <<  cnt << ' ' << cnt - pre << endl;
        pre= cnt;
        if (t % 10 == 0) {
            ff.pb({t, cnt});
        }
    }

    for (auto i : ff) {
        cout << i.fi << ' ' << i.se << endl;
    }
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