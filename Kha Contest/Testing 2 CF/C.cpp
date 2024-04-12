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

int psl[105][300];
int psr[105][300];
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    s = ' ' + s;
    int vt = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i] == '?') {
            vt = i;
        }
    }

    cout << vt << endl;


    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 220; j++) {
            psl[i][j] += psl[i-1][j];     
        }
        if (s[i] == '.' || s[i] == '?') continue;
        int x = int(s[i]);
        psl[i][x]++;
        // for (int j = 0; j <= 220; j++) {
        //     if (psl[i][j]) {
        //         cout << i << ' ' << char(j) << ' ' << psl[i][j] << endl;
        //     }
        // }
    }

        // for (int j = 0; j <= 220; j++) {
        //     if (psl[n][j]) {
        //         cout << char(j) << ' ' << psl[n][j] << endl;
        //     }     
        // }
    
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= 220; j++) {
            psr[i][j] += psr[i+1][j];    
        }
        
        if (s[i] == '.' || s[i] == '?') continue;
        int x = int(s[i]);
        psr[i][x]++;
    }
    bool ok = 0;
    for (int i = vt; i <= n; i++) {
        bool okk = 1;
        int x1, x2;
        for (int j = 65; j <= 90; j++) {
            x1 = psl[i][j];
            x2 = psl[i][j+32];
            // if (i == 11 ) {
            //    cout << i << ' ' << char(j)  << ' ' << char(j + 32) << endl;
            //     cout << x1 << ' ' << x2 <<endl;    
            // }
            if (x1 > x2) {
                okk = 0;
                break;
            }
        }   
        if (okk == 0) {
            break;
        }

        ok |= okk;
        if (okk) {
            cout <<"L   "<<  i << ' ' << x1 << ' ' << x2 << endl;
        }
    }
    for (int i = vt; i >= 1; i--) {
        bool okk = 1;
        int x1, x2;
        for (int j = 65; j <= 90; j++) {
            x1 = psr[i][j];
            x2 = psr[i][j+32];
            if (x1 > x2) {
                okk = 0;
                break;
            }
        }   

        if (okk == 0) {
            break;
        }

        if (okk) {
            cout <<"R   "<<  i << ' ' << x1 << ' ' << x2 << endl;
        }
        ok |= okk;
    }
    if (ok) {
        cout << "YES" <<endl;
    }
    else cout << "NO" <<endl;
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
    while (t--)    
    solve();
    
    return 0;
}