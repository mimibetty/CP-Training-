#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
 
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
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}


int lcs[3005][3005];
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string a,b;
    cin >> a;
    cin >> b;

    int n = a.size();
    int m = b.size();

    int lens = min(n,m);
    a = ' ' + a;
    b = ' ' + b;

     
    int l = 0, r = 0;
    int maxval = 0;
    vector<char>res;
    int cnt = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
                maxval = max(maxval, lcs[i][j]);
                if (maxval == lcs[i][j]) {
                    l = i;
                    r = j;
                }
            }
            else lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
        } 
    }   

    while (l && r) {
        if (a[l] == b[r]) {
            res.pb(a[l]);
            l--;
            r--;
            continue;  
        } 

        if (lcs[l-1][r] > lcs[l][r-1]) {
            l--;
        }
        else r--;
    }

    reverse(res.begin(),res.end());
    for (auto i : res) cout << i;
    // cout << lcs[n][m] << endl;

    return 0;
}