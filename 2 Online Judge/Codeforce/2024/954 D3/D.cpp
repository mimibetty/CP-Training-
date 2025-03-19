/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;

#define bit(n,i)  ((n>>i) & 1) 
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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    s = ' ' + s;

    // cout <<"begin   " << s << endl;
    
    int res = 1e9;
    for (int i = 1; i < n; i++) {
        vector<int>a;
        for (int j = 1; j < i; j++) {
            a.pb(s[j] - '0');
        }
        int x = (s[i] - '0') * 10 + (s[i+1] - '0'); 
        a.pb(x);
        // cout <<"TEST IX  " << i << ' ' << x << endl;
        for (int j = i + 2; j <= n; j++) {
            a.pb(s[j] - '0');
        }
        
        // cout << "TEST  " << endl;
        // for (auto j : a) cout << j << ' ';
        // cout << endl << endl;       


        int sum = 0;
        // int pre = 0;
        // for (auto j : a) {
        //     if (j == 0) {
        //         cout << 0 << endl;
        //         return;
        //     }
        //     if (j == 1) {

        //     }
        //     else sum += j;
        //     pre = j;
        // }
        bool ok = 1;
        for (int j = 0; j < a.size() ;j++) {
            if (a[j] != 1) {
                ok = 0;
            }

            if (a[j] == 0) {
                cout << 0 << endl;
                return;
            }
            if (a[j] == 1) {
            
            }
            else {
                sum += a[j];
            }
        }
        sum += ok;
        res = min(res, sum);

        // sum = 0;
        // pre = 0;
        // for (int j = a.size() - 1; j >= 0; j--) {
        //     if (a[j] == 1 && pre != 0) {

        //     }
        //     else sum += a[j];
        //     pre = a[j];
        // }       
        // res = min(res, sum);


        // cout << endl;
    }
    // cout << "res " << endl;
    cout << res << endl;
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


// 1121 x

// 101 + dau
// 901 x
// 1111111 x

// 1112
// 1121
