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

int n,m;
char a[2005][2005];
char res[2005][2005];
long long dp[1000005];
vector<char>trace[1000005];
void solve() {
    cin >> n >> m;
    map<char,int>d;
    int cnt= 0;
    int num1 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[a[i][j]]++;
            cnt++;
        }
    }
    // for (auto i : d) cout << i.fi << ' ' <<i.se << endl;
    dp[0] = 1;
    for (char i = 'a' ; i <= 'z'; i++) {
        if (d[i] == 1) {
            num1++;
            cnt--;
            continue;
        }
        for (int j = cnt; j >= 1; j--) {
            if (dp[j - d[i]] == 1) {
                dp[j] = 1;
                trace[j].pb(i);
                // cout << i << ' ' << j << endl;
            }
        }
    }
    // tru di truong hop cnt=1
    pii dis = {1e9,1e9};
    for (int i = 0; i <= cnt; i++) {
        if (dp[i]) {
            int x = i;
            int y = cnt-i;
            if (x > y) swap(x,y);
            if (y < dis.se) {
                dis = {x,y};
            }
        }
    }
    pii len ={1e4,1e4};
    for (int nn = n; nn <= n*2; nn++) {
        for (int mm = m; mm <= m * 2; mm++) {
            int z1 = nn*mm/2;
            int z2 = z1;
            if (nn % 2 == 1 && mm % 2 == 1) z2++;
            
            if (z1 + z2 >= num1 + cnt && z1 >= dis.fi && z2 >= dis.se) {
                if (nn*mm <= len.fi * len.se) {
                    int xx = nn, yy = mm;
                    if (xx > yy) swap(xx,yy);
                    len = {xx,yy};
                }
            } 
        }
    }
    map<char, int>d2;
    vector<char>gr1;
    vector<char>gr2;
    for (auto i : trace[dis.fi]) {
        for (int j = 1; j <= d[i]; j++) {
            gr1.pb(i);
            d2[i] = 1;
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        if (d2[i] == 0) {
            for (int j = 1; j <= d[i]; j++) {
                gr2.pb(i);
            }
        }
    }
    int vt = 0;
    for (int i = 1; i <= len.fi; i++) {
        for (int j = 1; j <= m; j += 2) {
            if (i % 2 == 0 && j == 1) j++;
            res[i][j] = gr1[vt];
        }
    }
    cout << len.fi << ' ' << len.se;
    EL;
    cout << dis.fi << ' ' << dis.se << endl;
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

