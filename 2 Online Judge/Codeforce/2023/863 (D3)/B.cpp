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

int n;
int x1;
int x2;
int yy1;
int y2;

bool checkkk(int x, int y, int f) {
    if (x != f && y != f) return false;
    if (x == f) {
        if (y >= f && y <= n + 1 - f) return true;
    }
    else {
        if (x >= f && x <= n + 1 - f) return true;
    }
    return false;
}

void solve() {
    cin >> n >> x1 >> yy1 >> x2 >> y2;
    int r1 = -1, r2 = -1;
    int tmpx1 = min(x1, n+1-x1);
    int tmpyy1 = min(yy1, n+1-yy1);
    int tmpx2 = min(x2, n+1-x2);
    int tmpy2 = min(y2, n+1-y2);
    if (checkkk(tmpx1, tmpyy1, tmpx1)) r1 = tmpx1;
    else {
        r1 = tmpyy1;
    }

    if (checkkk(tmpx2, tmpy2, tmpx2)) r2 = tmpx2;
    else {
        r2 = tmpy2;
    }

    cout <<abs(r2-r1) << endl;
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
        solve();
    } 
    return 0;
}