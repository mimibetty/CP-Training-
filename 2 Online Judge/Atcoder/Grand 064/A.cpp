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

int cnt[1005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cnt[i] = i;
    }
    int start = 1, end = n;
    if (cnt[n-2] == 1) {
        // cout << n << ' ' << n-2 << ' ' << n << ' ' << n - 1 << ' ' << n << ' ' << n-1 << endl; 
        return;
    }
    vector<int>res;
    int x = n;
    while (1) {
        for (int i = x; i >= 1; i--) {
            if (cnt[i] > 0) {
                res.pb(i);
                // cout << i << ' ';
                // cout << i << ' ' << cnt[i] << endl;;
                cnt[i]--;
                if (cnt[i] == 0) {
                    x = i + 1;
                    break;
                }
            }
            else {
                x = i + 1;
                break;
            }
        }
        if (cnt[n-2] == 1) {
            res.pb(n);
            res.pb(n-2);
            res.pb(n);
            res.pb(n-1);
            res.pb(n);
            res.pb(n-1);
            // cout << n << ' ' << n-2 << ' ' << n << ' ' << n - 1 << ' ' << n << ' ' << n-1 << endl; 
            break;
        }
        for (int i = x; i <= n; i++) {
            if (cnt[i] > 0) {
                res.pb(i);
                // cout << i << ' '; 
                // cout << i << ' ' << cnt[i] << endl;
                cnt[i]--;
            }
            else {
                x = i - 1;
                break;
            }
        }
        if (cnt[n-2] == 1) {
            res.pb(n);
            res.pb(n-2);
            res.pb(n);
            res.pb(n-1);
            res.pb(n);
            res.pb(n-1);
            // cout << n << ' ' << n-2 << ' ' << n << ' ' << n - 1 << ' ' << n << ' ' << n-1 << endl; 
            break;
        }
        x = n-1;
        // cout << endl;
    }
    for (int i = 0; i < res.size() - 1; i++) {
        if (abs(res[i] - res[i+1]) == 0 || abs(res[i] - res[i+1]) > 2) {
            swap(res[i], res[i-1]);
        }
    }
    for (auto i : res) cout << i << " ";

    int ok = -1;
    for (int i = 0; i < res.size() - 1; i++) {
        if (abs(res[i] - res[i+1]) == 0 || abs(res[i] - res[i+1]) > 2) {
            ok = i;
        }
    }
    if (abs(res[res.size() - 1] - res[0]) == 0 || abs(res[res.size() - 1] - res[0]) > 2) {
        ok = res.size() - 1;
    }
    cout << endl;
    cout << ok << endl;
    for (int i = 1; i <= n; i++) {
        cnt[i] = 0;
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
    cin >> t;
    while(t--)
    solve();
    
    return 0;
}