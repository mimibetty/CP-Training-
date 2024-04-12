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
ll a[100005];
ll b[100005];

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    int vt = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        sum += a[i];
        // if (a[i] > mx) {
        //     mx = a[i];
        //     vt = i;
        // }
    }
    int avg = sum / n;
    vector<int>dir;
    for (int i =  1;i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            dir.pb(j);
        }
    }
    ll res = 0, res2 = 0;
    for (int i = 0; i < dir.size() - 1; i++) {
        int x = (i%n) + 1;   
        int nxt = ((i+1)%n) + 1;
        if (a[x] > avg) {
            res += (a[x] - avg); 
            a[nxt] += (a[x] - avg);
            a[x] = avg;
        }
        // cout <<x << ' '<< a[x] << ' ' << res <<endl;
    }


    reverse(b + 1, b + 1 + n);
    for (int i = 0; i < dir.size() - 1; i++) {
        int x = (i%n) + 1;   
        int nxt = ((i+1)%n) + 1;
        if (b[x] > avg) {
            res2 += (b[x] - avg); 
            b[nxt] += (b[x] - avg);
            b[x] = avg;
        }
        // cout <<x << ' '<< a[x] << ' ' << res <<endl;
    }


    // cout << res << endl;
    // cout << res2 << endl;
    cout <<min(res2,res) << endl;
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