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

int num[200005];
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    char z = s[1];
    int cnt = 1;
    string f;
    int vt = 1;
    for (int i = 2; i <= n+1; i++) {
        if (z == s[i]) {
            cnt++;
        }
        else {
            f += z;
            num[vt] = cnt;
            vt++;
            cnt = 1;
            z = s[i]; 
        }
        // cout << i << ' ' << z << ' ' << cnt <<' ' << f<< endl;
    }
    int l = f.size();
    f = ' ' + f;
    bool ok = 0;
    int res = 0;
    int minval = 1e9;
    for (int i = 1; i <= l; i++) {
        if (f[i] == 'B' && num[i] > 1) {
            ok = 1;
            break;
        }
    } 
    // EL;
    // cout << f << endl;
    // for (int i = 1; i <= l; i++) cout << num[i] << ' ';
    // EL;
    if (ok == 1) {
        for (int i = 1; i <= l; i++) {
            if (f[i] == 'A') res += num[i];
        } 
        cout <<res << endl;
    }
    else {
        int bb =0,aa =0;
        int minval = 1e9;
        vector<int>tmp;
        for (int i = 1; i <= l; i++) {
            if (f[i] == 'B') {
                bb++;
            }  
            else {
                res += num[i];
                aa++;
                minval = min(minval, num[i]);
            }
        }   
        if (bb < aa) res -= minval;
        cout << res << endl;
    }
    // cout << f << endl;
    // for (int i = 1; i <= vt; i++) {
    //     cout << num[i] << ' ';
    // }
    // EL;
    for (int i = 1; i <= n; i++) num[i] = 0;
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