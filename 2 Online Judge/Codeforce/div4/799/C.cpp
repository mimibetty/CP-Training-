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
 
const int dx[4] = {-1,-1,+1,+1}, dy[4] = {-1,+1,-1,+1};
const long long oo = 1e18 + 7;
const int MOD = int(1e9)+7;
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}

char a[10][10];
bool check(int i, int j) {
    if (i >= 1 && i <= 8 && j >= 1 && j <= 8 && a[i][j] == '#') return 1;
    return 0;
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
    while (t--) {
        for (int i = 1; i <= 8 ;i++) {
            for (int j = 1; j <= 8; j++) {
                cin >> a[i][j];
            }
        }
        
        int cnt = 0;
        pair<int,int>vt;

        for (int i = 1;i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (a[i][j] == '.') continue;
         
                int num = 0;
                for (int z = 0; z < 4; z++) {
                    int vtx = i + dx[z];
                    int vty = j + dy[z];
                    if (check(vtx,vty) ) num++;                    
                }
                // cout << i << ' ' << j << ' ' << num << endl;

                if (num > cnt) {
                    cnt = num;
                    vt = {i,j};
                    // cout << cnt << ' ' << i << ' ' << j << endl;
                }
            }
        }
        cout << vt.fi <<  ' ' << vt.se << endl;
        // cout << cnt << endl;
        // cout << endl;
        // cout << a[6][1] << endl;
    }


    return 0;
}